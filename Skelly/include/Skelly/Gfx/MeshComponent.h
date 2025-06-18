#pragma once
#include <Skelly/Core/Skelly.h>
#include <memory>

namespace Skelly
{
    class ModelMeshNode;

    class SKELLY_API MeshComponent
    {
    public:
        MeshComponent() = default;
        MeshComponent(const MeshComponent& other) = delete;
        MeshComponent(MeshComponent&& other) = default;
        MeshComponent& operator=(const MeshComponent& other) = delete;
        MeshComponent& operator=(MeshComponent&& other) = default;
    protected:
        std::unique_ptr<ModelMeshNode> mNode;
    };
}