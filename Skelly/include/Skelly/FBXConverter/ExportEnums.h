#pragma once
#include <Skelly/Core/Skelly.h>

namespace Skelly
{
    enum class ExportType : UInt8
    {
        STATIC_MESH,
        SKELECTON_MESH,
        ACTION,
        MAX
    };
    enum class ExportParam : UInt8
    {
        EP_UV_COMPRESS,
        EP_NORMAL_COMPRESS,
        EP_SKIN_COMPRESS,
        EP_ACTION_COMPRESS,
    };
}