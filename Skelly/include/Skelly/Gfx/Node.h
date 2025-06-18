#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/SpatialNode.h>

namespace Skelly
{
    template<typename ChildType>
    class SKELLY_API Node : public SpatialNode, public std::enable_shared_from_this<Node>
    {
    public:
        Node() = default;
        Node(const Node& other) = delete;
        Node(Node&& other) = default;
        Node& operator=(const Node& other) = delete;
        Node& operator=(Node&& other) = default;
        virtual ~Node() = default;
    public:
        virtual std::optional<UInt8> AddChild(std::shared_ptr<ChildType> child);
        virtual bool DeleteChild(std::shared_ptr<ChildType> child);
        virtual bool DeleteChild(UInt8 index);
        std::shared_ptr<ChildType> GetChild(UInt8 index) const;
        std::vector<std::shared_ptr<ChildType>>& GetAllChild();
    protected:
        std::vector<std::shared_ptr<ChildType>> mChildren;
    };
}