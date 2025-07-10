#pragma once
#include <Skelly/Gfx/MeshNode.h>

namespace Skelly
{
    template<typename ChildType>
    class SKELLY_API ModelMeshNode : public MeshNode<ChildType>
    {
    public:
        ModelMeshNode() = default;
        ModelMeshNode(const ModelMeshNode& other) = delete;
        ModelMeshNode(ModelMeshNode&& other) = default;
        ModelMeshNode& operator=(const ModelMeshNode& other) = delete;
        ModelMeshNode& operator=(ModelMeshNode&& other) = default;
        virtual ~ModelMeshNode() = default;
    };
}