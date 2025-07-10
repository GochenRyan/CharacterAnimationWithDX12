#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/GfxEnums.h>
#include <Skelly/Gfx/IndexBuffer.h>
#include <Skelly/Gfx/VertexBuffer.h>
#include <memory>

namespace Skelly
{
    class SKELLY_API MeshData
    {
    public:
        MeshData() = default;
        virtual ~MeshData() = default;
        MeshData(const MeshData&) = delete;
        MeshData& operator=(const MeshData&) = delete;
        MeshData(MeshData&&) = default;
        MeshData& operator=(MeshData&&) = default;
    public:
        virtual UInt8 GetMeshDataType() = 0;
    private:
        std::unique_ptr<IndexBuffer> mIndexData;
        std::unique_ptr<VertexBuffer> mVertexBuffer;
        UInt8 mDataType{static_cast<UInt8>(GfxDataType::UINT)};
    };
}