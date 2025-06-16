#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/GfxEnums.h>

namespace Skelly
{
    class SKELLY_API DataBuffer
    {
    public:
        DataBuffer();
        virtual ~DataBuffer();
    private:
        UInt8 mDataType{static_cast<UInt8>(GfxDataType::UINT)};
        UInt32 mCount{0};
        void* mData{nullptr};
        UInt32 mSize{0};
        UInt8 mStructStride{0};
    };
}