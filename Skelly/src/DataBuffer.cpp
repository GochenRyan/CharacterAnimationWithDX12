#include <Skelly/Gfx/DataBuffer.h>
#include "DataBuffer.h"

using namespace Skelly;

DataBuffer::~DataBuffer()
{
    delete[] mData;
    mData = nullptr;
}

DataBuffer::DataBuffer(DataBuffer&& other) : 
    mDataType(other.mDataType),
    mCount(other.mCount),
    mData(other.mData),
    mSize(other.mSize),
    mStructStride(other.mStructStride)
{
    other.mData = nullptr;
}

DataBuffer& DataBuffer::operator=(DataBuffer&& other) 
{
    if (this != &other) 
    {
        delete[] mData;
        mData = nullptr;

        mDataType = other.mDataType;
        mCount = other.mCount;
        mData = other.mData;
        mSize = other.mSize;
        mStructStride = other.mStructStride;

        other.mData = nullptr;
    }
    return *this;
}