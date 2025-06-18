#include <Skelly/Gfx/SpatialNode.h>

using namespace DirectX;
using namespace Skelly;

void SpatialNode::SetParent(std::shared_ptr<SpatialNode> parent)
{
    mParent = parent;
}

void SpatialNode::UpdateTransform(Float64 dt)
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
