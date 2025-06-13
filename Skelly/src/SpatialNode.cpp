#include <Skelly/SpatialNode.h>

using namespace DirectX;
using namespace Skelly;

Skelly::SpatialNode::~SpatialNode()
{
}

void Skelly::SpatialNode::SetParent(std::shared_ptr<SpatialNode> parent)
{
    mParent = parent;
}

std::optional<UInt8> SpatialNode::AddChild(std::shared_ptr<SpatialNode> child)
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

bool SpatialNode::DeleteChild(std::shared_ptr<SpatialNode> child)
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

bool SpatialNode::DeleteChild(UInt8 index)
{
    if (index < mChildren.size()) 
    {
        mChildren[index]->mParent.reset();
        mChildren.erase(mChildren.begin() + index);
        return true;
    }
    return false;
}

std::shared_ptr<SpatialNode> SpatialNode::GetChild(UInt8 index) const
{
    if (index < mChildren.size()) 
    {
        return mChildren[index];
    }
    return nullptr;
}

std::vector<std::shared_ptr<SpatialNode>>& SpatialNode::GetAllChild()
{
    return mChildren;
}

void Skelly::SpatialNode::UpdateTransform(Float64 dt)
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
