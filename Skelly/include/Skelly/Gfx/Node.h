#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/SpatialNode.h>

namespace Skelly
{
    class BoneNode;
    class Geometry;
    class GeometryNode;

    template<typename ChildType>
    class Node : public SpatialNode, public std::enable_shared_from_this<ChildType>
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
        void UpdateNodeAll(Float64 dt) override;
    protected:
        std::vector<std::shared_ptr<ChildType>> mChildren;
    };

    template class SKELLY_API Node<BoneNode>;
    template class SKELLY_API Node<Geometry>;
    template class SKELLY_API Node<GeometryNode>;
}