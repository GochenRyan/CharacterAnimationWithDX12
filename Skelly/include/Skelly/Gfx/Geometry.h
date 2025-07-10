#pragma once
#include <Skelly/Gfx/SpatialNode.h>
#include <Skelly/Gfx/MeshData.h>

namespace Skelly
{
    class MeshData;

    class SKELLY_API Geometry : public SpatialNode
    {
    public:
        Geometry() = default;
        virtual ~Geometry() = default;
        Geometry(const Geometry& other) = delete;
        Geometry(Geometry&& other) = default;
        Geometry& operator=(const Geometry& other) = delete;
        Geometry& operator=(Geometry&& other) = default;
    public:
        void SetMeshData(std::unique_ptr<MeshData> meshData);
        MeshData* GetMeshData() const;
    private:
        std::unique_ptr<MeshData> mMeshData;
    };
}