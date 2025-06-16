#pragma once
#include <Skelly/Core/Skelly.h>
#include <Skelly/Gfx/GfxEnums.h>
#include <vector>

namespace Skelly
{
    

    class SKELLY_API VertexFormat
    {
    public:
        struct VertexFormatType
        {
            UInt32 Offset{0};
            UInt8 DataType{0};
            UInt8 Semantics{0};
            UInt8 SemanticsIndex{0};
            UInt8 InstanceDataStepRate{static_cast<UInt8>(GfxInputClassification::INPUT_CLASSIFICATION_PER_VERTEX_DATA)};
        };
    public:
        std::vector<GfxInputClassification> mVertexFormat;
    };
}