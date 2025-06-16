#pragma once
#include <Skelly/SpatialNode.h>

namespace Skelly
{
    class SKELLY_API MeshNode : public SpatialNode<MeshNode>
    {
    public:
        MeshNode() = default;
        MeshNode(const MeshNode& other) = delete;
        MeshNode(MeshNode&& other) = default;
        MeshNode& operator=(const MeshNode& other) = delete;
        MeshNode& operator=(MeshNode&& other) = default;
    };
}