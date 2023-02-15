#pragma once

#include "rapi_error.h"
#include "rapi_command.h"
#include "rapi_value.h"
#include "rapi_nil.h"
#include "rapi_stream.h"
#include "rapi_connection.h"

namespace rapi
{
    /*! \brief Main rapi client interface.
     *
     * This class manages the connection with the rapi server. All implemented commands are accessible through this interface.
     */
    class Client final
    {
    public:
        Client()              = delete;
        Client(const Client&) = delete;
        Client(Client&&)      = delete;

        /*! \brief Construct a rapi client and connect to a server.
         *
         * The constructor will initiate the connection to the rapi server.
         * Internally getaddrinfo() is used to resolve the host addres.
         *
         * \param addr Rapi server address.
         * \param port Rapi server port.
         */
        Client(const std::string& addr, uint16_t port);
        ~Client();

        /*! \brief error state of rapi client.
         *
         * This function returns the last critical error experienced by the rapi client.
         * If an error is recoverable it's not stored and error_code() will return ErrorCode::Success.
         *
         * \returns the last non-recoverable error or success.
         */
        ErrorCode error_code() const;

        /*! \brief Set a global var on the server.
         *
         * Use this function to set a global variable on the server.
         * Reading a global variable can be achieved with rapi::untility::get_var().
         * 
         * \param name Global variable name.
         * \param value New value assigned to global variable.
         * 
         * \returns ErrorCode::Success if the command is send succesfully.
         *
         */
        ErrorCode set_var(const std::string& name, const Value& value);

        /*! \brief Set a global var on the server.
         *
         * Use this function to set a global variable on the server.
         * Reading a global variable can be achieved with rapi::untility::get_var().
         *
         * \param name Global variable name.
         * \param value New value assigned to global variable.
         *
         * \returns ErrorCode::Success if the command is send succesfully.
         *
         * \see rapi::utility::get_var
         */
        ErrorCode set_var(const std::string& name, const Value::Ptr& value);

        /*! \brief Emit a lua signal on the server.
         *
         * This function will send the emit signal command. This will trigger the signal in lua on the rapi server.
         * 
         * \param signal_name Name of signal to emit.
         * \param thread_name Thread to send signal to, if empty all threads receive the signal.
         * \param client_name Client to send signal to.
         * 
         * \returns ErrorCode::Success if the command is send succesfully.
         */
        ErrorCode emit_signal(const std::string& signal_name, const std::string& thread_name, const std::string& client_name);

        /*! \brief Send message to lua thread(s).
         * 
         * Use this function to send a message to a lua thread. A message is like a signal with a payload.
         * 
         * \param signal_name Message name.
         * \param thread_name Thread to send message to, if empty all threads receive this message.
         * \param client_name Client to send message to.
         * \param value Message payload.
         * 
         * \returns ErrorCode::Success if the command is send succesfully.
         */
        ErrorCode send_message(const std::string& signal_name, const std::string& thread_name, const std::string& client_name, const Value& value);


        /*! \brief Send message to lua thread(s).
         *
         * Use this function to send a message to a lua thread. A message is like a signal with a payload.
         *
         * \param signal_name Message name.
         * \param thread_name Thread to send message to, if empty all threads receive this message.
         * \param client_name Client to send message to.
         * \param value Message payload.
         *
         * \returns ErrorCode::Success if the command is send succesfully.
         */
        ErrorCode send_message(const std::string& signal_name, const std::string& thread_name, const std::string& client_name, const Value::Ptr& value);

        /*! \brief Execute function on rapi server.
         *
         * This function can be used to execute a subset of the vr4max api on the rapi server.
         * All function that create/delete files are disabled. The arguments can be of type const rapi::Value& or const rapi::Value::Ptr&.
         * 
         * \param function_name VR4MAX api function to execute.
         * \param args The function arguments as rapi::Value or rapi::Value::Ptr.
         * 
         * \returns ErrorCode::Success is the command is send succesfully.
         */
        template<typename... Ts> ErrorCode execute_function(const std::string& function_name, const Ts&... args)
        {
            Stream stream;

            // command id
            stream.write(CommandID::ExecuteFunctionNoReply);

            stream.write_string(function_name);

            uint16_t size = (uint16_t)sizeof...(Ts);
            stream.write<uint16_t>(size);

            stream_arguments(stream, args...);

            return m_connection.send(stream);
        }

        /*! \brief Execute function on rapi server.
         *
         * This function can be used to execute a subset of the vr4max api on the rapi server and retrieve the return value.
         * All function that create/delete files are disabled. The arguments can be of type const rapi::Value& or const rapi::Value::Ptr&.
         * Since lua is capable of returning multiple values the return values are stored in a vector. If you are only interested in the first value returned use rapi::utility::execute_function_with_first_reply().
         *
         * \param return_values Output vector filled with the return values.
         * \param function_name VR4MAX api function to execute.
         * \param args The function arguments as rapi::Value or rapi::Value::Ptr.
         *
         * \returns ErrorCode::Success is the command is send succesfully.
         */
        template<typename... Ts> ErrorCode execute_function_with_reply(Value::List& return_values, const std::string& function_name, const Ts&... args)
        {
            Stream stream;

            stream.write(CommandID::ExecuteFunctionGetReply);
            stream.write_string(function_name);

            uint16_t size = (uint16_t)sizeof...(Ts);
            stream.write<uint16_t>(size);

            stream_arguments(stream, args...);

            ErrorCode err;
            if ((err = m_connection.send(stream)) != ErrorCode::Success)
            {
                std::cerr << "RAPIClient::execute_function_with_reply(): unable to send command to RAPI server." << std::endl;
                return err;
            }

            stream.clear();
            if ((err = m_connection.recv(stream)) != ErrorCode::Success)
            {
                std::cerr << "RAPIClient::execute_function_with_reply(): no reply received." << std::endl;
                return err;
            }

            if (stream.read<CommandID>() != CommandID::ExecuteFunctionReply)
            {
                std::cerr << "RAPIClient::execute_function_with_reply(): invalid reply received." << std::endl;
                return ErrorCode::UnexpectedReply;
            }

            int return_count = (int)stream.read<uint16_t>();

            return_values.clear();
            return_values.reserve(return_count);

            for (int i = 0; i < return_count; ++i)
                return_values.push_back(Value::stream_value_from(stream));

            return ErrorCode::Success;
        }

        /*! \brief Execute lua code on the rapi server.
         *
         * This function will send a piece of lua script to the server and execute it. If you are interested in receiving data from the script use run_lua_code_with_reply().
         * The script is executed in a sandboxed environment and can't delete files on the server system.
         * 
         * \param code Lua script to execute.
         * 
         * \returns ErrorCode::Success if the command is send succesfully.
         */
        ErrorCode run_lua_code(const std::string& code);

        /*! \brief Execute lua code on the rapi server and retrieve the return values.
        *
        * This function will send a piece of lua script to the server and execute it, if the script returns any values they are returned by this function.
        *
        * \param return_values Output vector filled with the return values.
        * \param code Lua script to execute.
        *
        * \returns ErrorCode::Success if the command is send succesfully.
        */
        ErrorCode run_lua_code_with_reply(Value::List& return_values, const std::string& code);

    private:
        void stream_arguments(Stream& stream)
        {
        }

        template<typename... Ts> void stream_arguments(Stream& stream, const Value& arg, const Ts&... args)
        {
            Value::stream_value_to(arg, stream);

            stream_arguments(stream, args...);
        }

        template<typename... Ts> void stream_arguments(Stream& stream, const Value::Ptr& arg, const Ts&... args)
        {
            if (!arg)
                Value::stream_value_to(Nil(), stream);
            else
                Value::stream_value_to(*arg, stream);

            stream_arguments(stream, args...);
        }

    private:
        Connection m_connection;
    };

}
