#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/GfxEnums.h>
#include <memory>

namespace Skelly
{
    class DataBuffer;

    class SKELLY_API VertexBuffer
    {
    public:
        VertexBuffer();
        virtual ~VertexBuffer();
    private:
        std::unique_ptr<DataBuffer> mData;
        UInt8 mDataType{static_cast<UInt8>(GfxDataType::UINT)};
        UInt32 mCount{0};
    };
}