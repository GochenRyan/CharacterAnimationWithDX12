#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/MeshData.h>

namespace Skelly
{
    class SKELLY_API TriangleSet : public MeshData
    {
    public:
        TriangleSet() = default;
        virtual ~TriangleSet() = default;
        TriangleSet(const TriangleSet&) = delete;
        TriangleSet& operator=(const TriangleSet&) = delete;
        TriangleSet(TriangleSet&&) = default;
        TriangleSet& operator=(TriangleSet&&) = default;
    public:
        UInt8 GetMeshDataType() override;
    };
}