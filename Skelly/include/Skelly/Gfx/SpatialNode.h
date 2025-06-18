#pragma once
#include <DirectXMath.h>
#include <MathHelper.h>
#include <memory>
#include <optional>
#include <vector>

#include <Skelly/Core/Skelly.h>

namespace Skelly
{
    class SKELLY_API SpatialNode
    {
    public:
        SpatialNode() = default;
        SpatialNode(const SpatialNode& other) = delete;
        SpatialNode(SpatialNode&& other) = default;
        SpatialNode& operator=(const SpatialNode& other) = delete;
        SpatialNode& operator=(SpatialNode&& other) = default;
        virtual ~SpatialNode() = default;
    public:
        void SetParent(std::shared_ptr<SpatialNode> parent);
        void UpdateTransform(Float64 dt);
    protected:
        std::weak_ptr<SpatialNode> mParent;
        DirectX::XMFLOAT4X4 mWorld{MathHelper::Identity4x4()};
        DirectX::XMFLOAT4X4 mLocal{MathHelper::Identity4x4()};
        bool mIsChanged{false};
    };
}