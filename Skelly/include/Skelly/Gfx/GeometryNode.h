#pragma once
#include <Skelly/Gfx/Node.h>

namespace Skelly
{
    class Geometry;

    class SKELLY_API GeometryNode : public Node<Geometry>
    {
    public:
        GeometryNode() = default;
        GeometryNode(const GeometryNode& other) = delete;
        GeometryNode(GeometryNode&& other) = default;
        GeometryNode& operator=(const GeometryNode& other) = delete;
        GeometryNode& operator=(GeometryNode&& other) = default;
    public:
        Geometry* GetGeometry(UInt32 i) const;
    };
}