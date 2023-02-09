#include "../include/rapi_client.h"

#include "../include/rapi_nil.h"

namespace rapi
{

Client::Client(const std::string& addr, uint16_t port)
	: m_connection(addr, port)
{
}

Client::~Client()
{
}

ErrorCode Client::error_code() const
{
    // just return connection error code since all client specific errors are recoverable
    return m_connection.error_code();
}

ErrorCode Client::set_var(const std::string& name, const Value& value)
{
	Stream stream;

	// commandid
	stream.write(CommandID::SetVar);
	
	// variable name
    stream.write_string(name);

	// variable value
	Value::stream_value_to(value, stream);

	// send to host
	return m_connection.send(stream);
}

ErrorCode Client::set_var(const std::string& name, const Value::Ptr& value)
{
    if (!value)
        set_var(name, Nil());

	return set_var(name, *value);
}

ErrorCode Client::emit_signal(const std::string& signal_name, const std::string& thread_name, const std::string& client_name)
{
    Stream stream;

    // command id
    stream.write(CommandID::EmitSignal);

    // names
    stream.write_string(signal_name);
    stream.write_string(thread_name);
    stream.write_string(client_name);

    return m_connection.send(stream);
}

ErrorCode Client::send_message(const std::string& signal_name, const std::string& thread_name, const std::string& client_name, const Value& value)
{
    Stream stream;

    // command id
    stream.write(CommandID::SendMsg);

    stream.write_string(signal_name);

    Value::stream_value_to(value, stream);

    stream.write_string(thread_name);
    stream.write_string(client_name);

    return m_connection.send(stream);
}

ErrorCode Client::send_message(const std::string& signal_name, const std::string& thread_name, const std::string& client_name, const Value::Ptr& value)
{
    if (!value)
        return send_message(signal_name, thread_name, client_name, Nil());

    return send_message(signal_name, thread_name, client_name, *value);
}

ErrorCode Client::run_lua_code(const std::string& code)
{
    Stream stream;

    stream.write(CommandID::RunLuaCodeNoReply);
    stream.write_string(code);

    return m_connection.send(stream);
}

ErrorCode Client::run_lua_code_with_reply(Value::List& return_values, const std::string& code)
{
    Stream stream;

    stream.write(CommandID::RunLuaCodeGetReply);
    stream.write_string(code);

    ErrorCode err;
    if ((err = m_connection.send(stream)) != ErrorCode::Success)
    {
        std::cerr << "RAPIClient::run_lua_code_with_reply(): unable to send command to RAPI server." << std::endl;
        return err;
    }

    stream.clear();

    if ((err = m_connection.recv(stream)) != ErrorCode::Success)
    {
        std::cerr << "RAPIClient::run_lua_code_with_reply(): no reply received." << std::endl;
        return err;
    }

    if (stream.read<CommandID>() != CommandID::RunLuaCodeReply)
    {
        std::cerr << "RAPIClient::run_lua_code_with_reply(): invalid reply received." << std::endl;

        // since the complete reply has been read, this is a recoverable error
        return ErrorCode::UnexpectedReply;
    }

    int size = (int)stream.read<uint16_t>();
    
    return_values.clear();
    return_values.reserve(size);

    for (int i = 0; i < size; ++i)
        return_values.push_back(Value::stream_value_from(stream));

    return ErrorCode::Success;
}

}
