#include "../include/rapi_connection.h"

#include <iostream>

#ifdef _WIN32
	#include <WS2tcpip.h>

	#pragma comment (lib, "Ws2_32.lib")
#else
	#include <unistd.h>
	#include <netdb.h>

	#define INVALID_SOCKET (-1)
	#define SOCKET_ERROR (-1)
#endif

namespace rapi
{

const uint8_t Connection::PROTOCOL_VERSION = 1;
const size_t  Connection::HEADER_SIZE      = sizeof(uint32_t) + sizeof(uint8_t);

Connection::Connection(const std::string& addr, uint16_t port)
	: m_error(ErrorCode::Success)
	, m_socket(INVALID_SOCKET)
{
	int res;
	
#ifdef _WIN32
	// initialize winsock
	WSAData data;
	res = WSAStartup(MAKEWORD(2, 2), &data);
	if (res != 0)
	{
		std::cerr << "RAPIConnection::RAPIConnection(" << addr << ", " << port << "): unable to initialize winsock." << std::endl;
        return_error(ErrorCode::WinsockInitFailed);
		return;
	}
#endif

	// host address hints
	addrinfo hints = {};
	hints.ai_family   = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;

	std::string port_str = std::to_string(port);

	addrinfo* host_address = nullptr;

	// resolve host
	res = getaddrinfo(addr.c_str(), port_str.c_str(), &hints, &host_address);
	if (res != 0)
	{
		std::cerr << "RAPIConnection::RAPIConnection(" << addr << ", " << port << "): unable to resolve host address." << std::endl;
        return_error(ErrorCode::ResolveHostFailed);
		return;
	}

	// try host addresses until we are connected
	for (addrinfo* addr = host_address; addr != nullptr; addr = addr->ai_next)
	{
		m_socket = socket(addr->ai_family, addr->ai_socktype, addr->ai_protocol);
		if (m_socket == INVALID_SOCKET)
			continue;

		res = connect(m_socket, addr->ai_addr, addr->ai_addrlen);

		// done?
		if (res != SOCKET_ERROR)
			break;

		// cleanup for next try
#ifdef _WIN32
		closesocket(m_socket);
#else
		close(m_socket);
#endif
		m_socket = INVALID_SOCKET;
	}

	freeaddrinfo(host_address);

	if (m_socket == INVALID_SOCKET)
	{
		std::cerr << "RAPIConnection::RAPIConnection(" << addr << ", " << port << "): unable to connect to host." << std::endl;
        return_error(ErrorCode::ConnectionFailed);
		return;
	}

    //std::cout << "RAPIConnection::RAPIConnection(" << addr << ", " << (int)port << "): connection established." << std::endl;
}

Connection::~Connection()
{
	if (m_socket != INVALID_SOCKET)
	{
#ifdef _WIN32
		closesocket(m_socket);
#else
		close(m_socket);
#endif
	}

#ifdef _WIN32
	WSACleanup();
#endif
}

ErrorCode Connection::send(Stream& payload)
{
    if (error_code() != ErrorCode::Success)
        return error_code();

    // check payload size, this is a recoverable error!
	size_t payload_size = payload.size();
	if (payload_size == 0)
		return ErrorCode::NoPayload;

	uint32_t message_size = HEADER_SIZE + payload_size;

	// message size and protocol version
    if (socket_send((const char*)&message_size, sizeof(uint32_t)) != ErrorCode::Success)
        return error_code();

    if (socket_send((const char*)&PROTOCOL_VERSION, sizeof(uint8_t)) != ErrorCode::Success)
        return error_code();

	// fetch payload
	uint8_t* payload_data = new uint8_t[payload_size];
	payload.read(payload_data, payload_size);

	// send payload
    if (socket_send((const char*)payload_data, payload_size) != ErrorCode::Success)
    {
        delete[] payload_data;
        return error_code();
    }

	// free
	delete[] payload_data;

	return ErrorCode::Success;
}

ErrorCode Connection::recv(Stream& payload)
{
    if (error_code() != ErrorCode::Success)
        return error_code();

	uint32_t message_size = 0;
    if (socket_recv((char*)&message_size, sizeof(uint32_t)) != ErrorCode::Success)
        return error_code();

	// sane message is over 5 bytes long
	if (message_size <= HEADER_SIZE)
	{
		std::cerr << "RAPIConnection::recv(): invalid packet dropped." << std::endl;
		return return_error(ErrorCode::PayloadTooShort);
	}

	uint8_t protocol_version = 0;
    if (socket_recv((char*)&protocol_version, sizeof(uint8_t)) != ErrorCode::Success)
        return error_code();

	if (protocol_version != PROTOCOL_VERSION)
	{
		std::cerr << "RAPIConnection::recv(): protocol version mismatch, local version = " << (int)PROTOCOL_VERSION << ", remote version = " << (int)protocol_version << std::endl;
		return return_error(ErrorCode::ProtocolVersionMismatch);
	}

	size_t   payload_size = message_size - HEADER_SIZE;
	uint8_t* payload_data = new uint8_t[payload_size];

	if (socket_recv((char*)payload_data, payload_size) != ErrorCode::Success)
	{
		delete[] payload_data;
		return error_code();
	}

	payload.write(payload_data, payload_size);

	delete[] payload_data;

	return ErrorCode::Success;
}

ErrorCode Connection::return_error(ErrorCode e)
{
    m_error = e;
    return e;
}

ErrorCode Connection::socket_send(const char* data, int size)
{
    int total_send = 0;
    while (total_send < size)
    {
        int next_send = ::send(m_socket, data, size - total_send, 0);
        if (next_send < 0)
        {
            std::cerr << "RAPIConnection::socket_send(): connection error!" << std::endl;
            return return_error(ErrorCode::SendFailed);
        }

        total_send += next_send;
        data       += next_send;
    }

    return ErrorCode::Success;
}

ErrorCode Connection::socket_recv(char* data, int size)
{

    int total_recv = 0;
    while (total_recv < size)
    {
        int next_recv = ::recv(m_socket, data, size - total_recv, 0);
        if (next_recv <= 0)
        {
            std::cerr << "RAPIConnection::socket_recv(): connection error!" << std::endl;
            return return_error(ErrorCode::ReceiveFailed);
        }

        total_recv += next_recv;
        data       += next_recv;
    }

    return ErrorCode::Success;
}

}
