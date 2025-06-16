#include <Skelly/SpatialNode.h>

using namespace DirectX;
using namespace Skelly;

template <typename Derived>
Skelly::SpatialNode<Derived>::~SpatialNode()
{
}

template <typename Derived>
void Skelly::SpatialNode<Derived>::SetParent(std::shared_ptr<Derived> parent)
{
    mParent = parent;
}

template <typename Derived>
std::optional<UInt8> SpatialNode<Derived>::AddChild(std::shared_ptr<Derived> child)
{
    if (!child || child.get() == this) 
    {
        return std::nullopt;
    }

    for (const auto& c : mChildren) 
    {
        if (c == child) {
            return std::nullopt;
        }
    }

    child->mParent = shared_from_this();
    mChildren.push_back(child);

    return static_cast<UInt8>(mChildren.size() - 1);
}

template <typename Derived>
bool SpatialNode<Derived>::DeleteChild(std::shared_ptr<Derived> child)
{
    for (auto it = mChildren.begin(); it != mChildren.end(); ++it) 
    {
        if (*it == child) 
        {
            (*it)->mParent.reset();
            mChildren.erase(it);
            return true;
        }
    }
    return false;
}

template <typename Derived>
bool SpatialNode<Derived>::DeleteChild(UInt8 index)
{
    if (index < mChildren.size()) 
    {
        mChildren[index]->mParent.reset();
        mChildren.erase(mChildren.begin() + index);
        return true;
    }
    return false;
}

template <typename Derived>
std::shared_ptr<Derived> SpatialNode<Derived>::GetChild(UInt8 index) const
{
    if (index < mChildren.size()) 
    {
        return mChildren[index];
    }
    return nullptr;
}

template <typename Derived>
std::vector<std::shared_ptr<Derived>>& SpatialNode<Derived>::GetAllChild()
{
    return mChildren;
}

template <typename Derived>
void SpatialNode<Derived>::UpdateTransform(Float64 dt)
{
    auto sp = mParent.lock();
    if (sp && sp->mIsChanged)
    {
        mIsChanged = true;
    }

    if (mIsChanged)
    {
        if (sp)
        {
            XMMATRIX localMatrix = XMLoadFloat4x4(&mLocal);
            XMMATRIX parentWorldMatrix = XMLoadFloat4x4(&sp->mWorld);
            XMMATRIX globalMatrix = XMMatrixMultiply(localMatrix, parentWorldMatrix);
            XMStoreFloat4x4(&mWorld, globalMatrix);
        }
        else
            mWorld = mLocal;
    }
}
