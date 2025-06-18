#pragma once
#include <Skelly/Gfx/Node.h>

namespace Skelly
{
    class BoneNode;

    class SKELLY_API Skeleton : public Node<BoneNode>
    {
    public:
        Skeleton() = default;
        Skeleton(const Skeleton& other) = delete;
        Skeleton(Skeleton&& other) = default;
        Skeleton& operator=(const Skeleton& other) = delete;
        Skeleton& operator=(Skeleton&& other) = default;
    public:
        void CreateBoneNodes();
    private:
        std::vector<std::shared_ptr<BoneNode>> mBoneNodes;
    };
}