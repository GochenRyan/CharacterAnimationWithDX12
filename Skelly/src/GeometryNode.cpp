#include <Skelly/Gfx/GeometryNode.h>

using namespace Skelly;

Geometry* GeometryNode::GetGeometry(UInt32 i) const
{
    if (i >= mChildren.size())
        return nullptr;
    
    return mChildren[i].get();
}