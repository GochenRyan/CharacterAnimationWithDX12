#include <Skelly/Gfx/Node.h>

using namespace Skelly;

template <typename ChildType>
std::optional<UInt8> Node<ChildType>::AddChild(std::shared_ptr<ChildType> child)
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

template <typename ChildType>
bool Node<ChildType>::DeleteChild(std::shared_ptr<ChildType> child)
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

template <typename ChildType>
bool Node<ChildType>::DeleteChild(UInt8 index)
{
    if (index < mChildren.size()) 
    {
        mChildren[index]->mParent.reset();
        mChildren.erase(mChildren.begin() + index);
        return true;
    }
    return false;
}

template <typename ChildType>
std::shared_ptr<ChildType> Node<ChildType>::GetChild(UInt8 index) const
{
    if (index < mChildren.size()) 
    {
        return mChildren[index];
    }
    return nullptr;
}

template <typename ChildType>
std::vector<std::shared_ptr<ChildType>>& Node<ChildType>::GetAllChild()
{
    return mChildren;
}