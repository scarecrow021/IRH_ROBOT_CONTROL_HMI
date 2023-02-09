#pragma once

namespace rapi
{

    enum class ErrorCode
    {
        Success,
        WinsockInitFailed,
        ResolveHostFailed,
        ConnectionFailed,
        NoPayload,
        PayloadTooShort,
        ProtocolVersionMismatch,
        SendFailed,
        ReceiveFailed,
        UnexpectedReply
    };

    const char* error_to_string(ErrorCode e);
}