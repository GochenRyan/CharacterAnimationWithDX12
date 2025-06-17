#include <Skelly/Gfx/GfxEnums.h>
#include <Skelly/Gfx/LineSet.h>

using namespace Skelly;

UInt8 LineSet::GetMeshDataType() 
{
    return static_cast<UInt8>(GfxMeshDataType::LINE);
}

bool LineSet::CreateIndex(UInt8 lineType)
{
    return false;
}