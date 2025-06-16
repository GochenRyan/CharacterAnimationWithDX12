#include <Skelly/Skeleton.h>
#include <Skelly/BoneNode.h>

using namespace Skelly;

void Skeleton::CreateBoneNodes()
{
    mBoneNodes.clear();
    for (auto child : mChildren)
    {
        child->GetAllNodes(mBoneNodes);
    }
}