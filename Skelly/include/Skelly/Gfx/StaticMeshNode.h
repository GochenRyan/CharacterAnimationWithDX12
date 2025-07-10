#pragma once
#include <Skelly/Gfx/ModelMeshNode.h>

namespace Skelly
{
    class GeometryNode;

    class SKELLY_API StaticMeshNode : public ModelMeshNode<GeometryNode>
    {
    public:
        StaticMeshNode() = default;
        StaticMeshNode(const StaticMeshNode& other) = delete;
        StaticMeshNode(StaticMeshNode&& other) = default;
        StaticMeshNode& operator=(const StaticMeshNode& other) = delete;
        StaticMeshNode& operator=(StaticMeshNode&& other) = default;
    public:
        static const StaticMeshNode* GetDefault()
        {
            return msDefault.get();
        }
    private:
        static inline std::unique_ptr<StaticMeshNode> msDefault = nullptr;
    };
}