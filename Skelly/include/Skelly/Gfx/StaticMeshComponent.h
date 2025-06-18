#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/MeshComponent.h>

#include <memory>

namespace Skelly
{
    class ModelMeshNode;

    class SKELLY_API StaticMeshComponent : MeshComponent
    {
    public:
        StaticMeshComponent() = default;
        StaticMeshComponent(const StaticMeshComponent& other) = delete;
        StaticMeshComponent(StaticMeshComponent&& other) = default;
        StaticMeshComponent& operator=(const StaticMeshComponent& other) = delete;
        StaticMeshComponent& operator=(StaticMeshComponent&& other) = default;
    protected:
        std::unique_ptr<ModelMeshNode> mNode;
    };
}