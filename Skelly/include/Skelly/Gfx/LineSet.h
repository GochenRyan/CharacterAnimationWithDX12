#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/MeshData.h>

namespace Skelly
{
    class SKELLY_API LineSet : public MeshData
    {
    public:
        LineSet() = default;
        virtual ~LineSet() = default;
        LineSet(const LineSet&) = delete;
        LineSet& operator=(const LineSet&) = delete;
        LineSet(LineSet&&) = default;
        LineSet& operator=(LineSet&&) = default;
    public:
        UInt8 GetMeshDataType() override;
        bool CreateIndex(UInt8 lineType);
    };
}
