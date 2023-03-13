#pragma once

#include "rapi_error.h"
#include "rapi_stream.h"

#ifdef _WIN32
	#include <cppHeaders.hpp>
	
	#define RAPI_SOCKET SOCKET
#else
	#include <sys/socket.h>

	#define RAPI_SOCKET int
#endif

namespace rapi
{
    /*! \brief RAPI Client connection.
     *
     * The Connection class manages the connection to the RAPI server.
     * It is used by the Client in order to send/receive commands. You do not have to use this class yourself.
     */
    class Connection final
    {
    public:
        //! \brief Protocol version, currently 1.
        static const uint8_t PROTOCOL_VERSION;
        //! \brief RAPI Protocol packet header size.
        static const size_t  HEADER_SIZE;

    public:
        Connection(const Connection&) = delete;

        Connection(const std::string& addr, uint16_t port);
        ~Connection();

        ErrorCode error_code() const { return m_error; }

        ErrorCode send(Stream& payload);
        ErrorCode recv(Stream& payload);

    private:
        ErrorCode return_error(ErrorCode e);

        ErrorCode socket_send(const char* data, int size);
        ErrorCode socket_recv(char* data, int size);

    private:
        ErrorCode   m_error;
        RAPI_SOCKET m_socket;
    };

}