#pragma once
#include <DirectXMath.h>
#include <MathHelper.h>
#include <memory>
#include <optional>
#include <vector>

#include <Skelly/Core/Skelly.h>

namespace Skelly
{
    template<typename Derived>
    class SKELLY_API SpatialNode : public std::enable_shared_from_this<Derived>
    {
    public:
        SpatialNode() = default;
        SpatialNode(const SpatialNode& other) = delete;
        SpatialNode(SpatialNode&& other) = default;
        SpatialNode& operator=(const SpatialNode& other) = delete;
        SpatialNode& operator=(SpatialNode&& other) = default;
        virtual ~SpatialNode();

    public:
        void SetParent(std::shared_ptr<Derived> parent);
        virtual std::optional<UInt8> AddChild(std::shared_ptr<Derived> child);
        virtual bool DeleteChild(std::shared_ptr<Derived> child);
        virtual bool DeleteChild(UInt8 index);
        std::shared_ptr<Derived> GetChild(UInt8 index) const;
        std::vector<std::shared_ptr<Derived>>& GetAllChild();
        void UpdateTransform(Float64 dt);
    protected:
        DirectX::XMFLOAT4X4 mWorld{MathHelper::Identity4x4()};
        DirectX::XMFLOAT4X4 mLocal{MathHelper::Identity4x4()};
        std::weak_ptr<Derived> mParent;
        std::vector<std::shared_ptr<Derived>> mChildren;
        bool mIsChanged{false};
    };
}