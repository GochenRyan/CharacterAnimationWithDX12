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
        VertexBuffer() = default;
        virtual ~VertexBuffer() = default;
        VertexBuffer(const VertexBuffer&) = delete;
        VertexBuffer& operator=(const VertexBuffer&) = delete;
        VertexBuffer(VertexBuffer&&) = default;
        VertexBuffer& operator=(VertexBuffer&&) = default;
    private:
        std::unique_ptr<DataBuffer> mData;
        UInt8 mDataType{static_cast<UInt8>(GfxDataType::UINT)};
        UInt8 mOneVertexSize{0};
        UInt32 mCount{0};
    };
}