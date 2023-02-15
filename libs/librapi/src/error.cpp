#include "../include/rapi_error.h"

namespace rapi
{

const char* error_to_string(ErrorCode e)
{
    switch (e)
    {
    case ErrorCode::Success:
        return "success";
    case ErrorCode::WinsockInitFailed:
        return "unable to initialize winsock";
    case ErrorCode::ResolveHostFailed:
        return "unable to resolve host address";
    case ErrorCode::ConnectionFailed:
        return "unable to connect to host address";
    case ErrorCode::NoPayload:
        return "trying to send a message without a payload is not allowed";
    case ErrorCode::PayloadTooShort:
        return "message with invalid payload size received";
    case ErrorCode::ProtocolVersionMismatch:
        return "host is using an incompatible protocol version";
    case ErrorCode::SendFailed:
        return "unable to send data, connection lost";
    case ErrorCode::ReceiveFailed:
        return "unable to receive data, connection lost";
    case ErrorCode::UnexpectedReply:
        return "unexpected command id in reply";
    default:
        ;
    }

    return "unknown error";
}

}
