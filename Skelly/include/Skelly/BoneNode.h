#pragma once
#include <Skelly/SpatialNode.h>

namespace Skelly
{
    class Skeleton;

    class SKELLY_API BoneNode : public SpatialNode<BoneNode>
    {
    public:
        BoneNode() = default;
        BoneNode(const BoneNode& other) = delete;
        BoneNode(BoneNode&& other) = default;
        BoneNode& operator=(const BoneNode& other) = delete;
        BoneNode& operator=(BoneNode&& other) = default;
    public:
        void GetAllNodes(std::vector<std::shared_ptr<BoneNode>>& allNodes);
    };
}