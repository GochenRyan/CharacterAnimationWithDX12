#include <Skelly/SkeletonMeshNode.h>

using namespace Skelly;

void SkeletonMeshNode::SetSkeleton(std::unique_ptr<Skeleton> skeleton)
{
    mSkeleton = std::move(skeleton);
}