#pragma once

#include <cstdint>

namespace rapi
{
    //! \brief Protocol command id's, used when encoding/decoding network packets.
    enum class CommandID : uint8_t
    {
        SetVar                  = 0,
        EmitSignal              = 1,
        SendMsg                 = 2,
        ExecuteFunctionNoReply  = 3,
        ExecuteFunctionGetReply = 4,
        ExecuteFunctionReply    = 5,
        RunLuaCodeNoReply       = 6,
        RunLuaCodeGetReply      = 7,
        RunLuaCodeReply         = 8,
    
        RoundTrip               = 254,
        RoundTripReponse        = 255
    };

}