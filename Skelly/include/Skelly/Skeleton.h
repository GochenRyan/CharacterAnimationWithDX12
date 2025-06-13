#pragma once
#include <Skelly/SpatialNode.h>

namespace Skelly
{
    class BoneNode;

    class SKELLY_API Skeleton : public SpatialNode
    {
    private:
        std::vector<std::shared_ptr<BoneNode>> mBoneNodes;
    };
}