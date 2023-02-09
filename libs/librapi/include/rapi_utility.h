#pragma once

#include <string>

namespace rapi
{
    class Client;

    namespace utility
    {
        /*! \brief Fetch vr4max version from RAPI server.
         *
         * This function will use the ExecuteFunctionWithReply command to fetch the vr4max version from the RAPI server.
         * If the connection is invalid or we are not connected to a valid vr4max instance this function will return an empty string.
         *
         * \param client rapi::Client instance which has to be connected to a rapi server.
         *
         * \returns vr4max version string
         */
        std::string get_vr4max_version(Client& client);

        /*! \brief Fetch the vr4max lua api version number from the RAPI server.
         *
         * This function uses the ExecuteFunctionWithReply command to fetch the lua api version available on a RAPI server.
         * If the connection is invalid or we are not connected to a valid vr4max instance this function will return an empty string.
         *
         * \param client rapi::Client instance which has to be connected to a rapi server.
         *
         * \returns lua api version string
         */
        std::string get_lua_api_version(Client& client);

        /*! \brief Fetch variable.
         *
         * The RAPI protocol doesn't feature a dedicated get var command. 
         * This utility function will use ExecuteFunctionWithReply in order to acquire the contents of a specific variable.
         * If client is not connected to a valid vr4max instance or the variable doesn't exist this function will return Nil.
         * 
         * \returns Variable value or Nil
         */
        Value::Ptr get_var(Client& client, const std::string& name);

        /*! \brief Execute function and return only one replied value.
         * 
         * Lua functions can return multiple values, this is why the reply is always stored in a vector.
         * Most of the time we are only interested in the first/only return value, this function can be used to ignore all other replies.
         * Beware that all return values are still send over the net work, they are ignored client side.
         * 
         * \param client rapi::Client instance which has to be connected to a rapi server.
         * \param function_name Name of the function to execute on the server.
         * \param args Function arguments (must be of type rapi::Value or rapi::Value::Ptr)
         * 
         * \returns The first return value or nullptr if we encountered an error.
         */
        template<typename... Ts> Value::Ptr execute_function_with_first_reply(Client& client, const std::string& function_name, const Ts&... args)
        {
            std::vector<Value::Ptr> values;
            if (client.execute_function_with_reply(values, function_name, args...) != ErrorCode::Success)
                return nullptr;

            if (values.empty())
                return nullptr;

            return std::move(values[0]);
        }
    }
}
