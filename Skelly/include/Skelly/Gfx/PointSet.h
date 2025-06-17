#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/MeshData.h>

namespace Skelly
{
    class SKELLY_API PointSet : public MeshData
    {
    public:
        PointSet() = default;
        virtual ~PointSet() = default;
        PointSet(const PointSet&) = delete;
        PointSet& operator=(const PointSet&) = delete;
        PointSet(PointSet&&) = default;
        PointSet& operator=(PointSet&&) = default;
    public:
        UInt8 GetMeshDataType() override;
        bool CreateIndex();
    };
}
