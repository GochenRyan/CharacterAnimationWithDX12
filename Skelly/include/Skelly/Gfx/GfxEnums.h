#pragma once
#include <Skelly/Core/Skelly.h>

namespace Skelly
{
    enum class GfxInputClassification : UInt8
    {
        INPUT_CLASSIFICATION_PER_VERTEX_DATA,
        INPUT_CLASSIFICATION_PER_INSTANCE_DATA
    };

    enum class GfxDataType : UInt8
    {
        FLOAT32_1,      // (value, 0., 0., 1.)
        FLOAT32_2,      // (value.x, value.y, 0., 1.)
        FLOAT32_3,      // (value.x, value.y, value.z, 1.)
        FLOAT32_4,      // (value.x, value.y, value.z, value.w.)

        USHORT,	        // Index buffer 
        UINT,	        // Index buffer		 

        UBYTE4,	        // 4D unsigned byte
        UBYTE4N,        // Each of 4 bytes is normalized by dividing to 255.0

        SHORT2,	        // 2D signed short expanded to (value, value, 0., 1.)
        SHORT2N,	    // 2D signed short normalized (v[0]/32767.0,v[1]/32767.0,0,1)
        USHORT2N,       // 2D unsigned short normalized (v[0]/65535.0,v[1]/65535.0,0,1)

        SHORT4,	        // 4D signed short expanded to (value, value, value, value)
        SHORT4N,	    // 4D signed short normalized (v[0]/32767.0,v[1]/32767.0,v[2]/32767.0,v[3]/32767.0)
        USHORT4N,       // 4D unsigned short normalized (v[0]/65535.0,v[1]/65535.0,v[2]/65535.0,v[3]/65535.0)

        FLOAT16_2,      // Two 16-bit floating point values, expanded to (value, value, 0, 1)
        FLOAT16_4,      // Four 16-bit floating point values

        COLOR,	        // 4D packed unsigned bytes mapped to 0. to 1. range
                        // Input is in D3DCOLOR format (ARGB) expanded to (R, G, B, A)
        SINT,	
        SINT2,
        SINT3,
        SINT4,

        UINT2,
        UINT3,
        UINT4,

        FLOAT16_1,
        UBYTE,			// use byte address buffer

        STRUCT = 127,	// use struct buffer
        MAXNUM = 128
    };

    enum class GfxVertexSemantic : UInt8
    {
        POSITION,
        TEXCOORD,
        NORMAL,
        TANGENT,
        BINORMAL,
        PSIZE,
        COLOR,
        VERTEX_ID,
        BLENDWEIGHT,
        BLENDINDICES,
        MATERIAL_INSTANCE,
        MAX
    };

    enum class GfxMeshDataType : UInt8
    {
        POINT,
        LINE,
        TRIANGLE,
        CONTROL_POINT_4,
        MAX
    };

    enum class GfxLineType : UInt8
    {
        OPEN,
        CLOSE,
        SEGMENT,
        MAX
    };
}