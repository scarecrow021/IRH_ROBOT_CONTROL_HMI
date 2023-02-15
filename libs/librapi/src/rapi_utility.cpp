#include "../include/rapi.h"
#include "../include/rapi_utility.h"

namespace rapi
{
namespace utility
{

std::string get_vr4max_version(Client& client)
{
    Value::List return_values;
    if (client.execute_function_with_reply(return_values, "vmxApplicationVersion", Bool(true), Bool(true)) != ErrorCode::Success)
        return std::string();

    if (return_values.empty())
        return std::string();

    return return_values.front()->as_string();
}

std::string get_lua_api_version(Client& client)
{
    Value::List return_values;
    if (client.execute_function_with_reply(return_values, "vmxGetLuaAPIVersionNr") != ErrorCode::Success)
        return std::string();

    if (return_values.empty())
        return std::string();

    return return_values.front()->as_string();
}

Value::Ptr get_var(Client& client, const std::string& name)
{
    Value::List return_values;
    if (client.execute_function_with_reply(return_values, "vmxGetVar", String(name)) != ErrorCode::Success)
        return Nil::create();

    if (return_values.empty())
        return Nil::create();

    return std::move(return_values.front());
}

}
}
