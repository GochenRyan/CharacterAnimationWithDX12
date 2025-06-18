#pragma once
#include <Skelly/Gfx/Node.h>

namespace Skelly
{
    template<typename ChildType>
    class SKELLY_API MeshNode : public Node
    {
    public:
        MeshNode() = default;
        MeshNode(const MeshNode& other) = delete;
        MeshNode(MeshNode&& other) = default;
        MeshNode& operator=(const MeshNode& other) = delete;
        MeshNode& operator=(MeshNode&& other) = default;
    public:
        bool IsReceiveShadow;
        bool IsCastShadow;
        bool IsLighted;
    };
}