#include <Skelly/Gfx/GfxEnums.h>
#include <Skelly/Gfx/PointSet.h>

using namespace Skelly;

UInt8 PointSet::GetMeshDataType()
{
    return static_cast<UInt8>(GfxMeshDataType::POINT);
}

bool PointSet::CreateIndex()
{
    return false;
}