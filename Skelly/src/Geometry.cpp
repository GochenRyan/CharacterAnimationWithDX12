#include <Skelly/Gfx/Geometry.h>
using namespace Skelly;

void Geometry::SetMeshData(std::unique_ptr<MeshData> meshData)
{
    mMeshData = std::move(meshData);
}

MeshData* Skelly::Geometry::GetMeshData() const
{
    return mMeshData.get();
}