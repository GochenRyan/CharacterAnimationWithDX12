#pragma once
#include <Skelly/Gfx/GeometryNode.h>
#include <Skelly/Gfx/ModelMeshNode.h>
#include <Skelly/Skeleton.h>

namespace Skelly
{
    class SKELLY_API SkeletonMeshNode : public ModelMeshNode<GeometryNode>
    {
    public:
        void SetSkeleton(std::unique_ptr<Skeleton> skeleton);
    private:
        std::unique_ptr<Skeleton> mSkeleton;
    };
}