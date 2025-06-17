#include <Skelly/Gfx/GfxEnums.h>
#include <Skelly/Gfx/TriangleSet.h>

using namespace Skelly;

UInt8 TriangleSet::GetMeshDataType()
{
    return static_cast<UInt8>(GfxMeshDataType::TRIANGLE);
}