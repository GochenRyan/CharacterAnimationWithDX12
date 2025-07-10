#include <Skelly/Gfx/DataBuffer.h>

using namespace Skelly;

DataBuffer::~DataBuffer()
{
    delete[] mData;
    mData = nullptr;
}

DataBuffer::DataBuffer(DataBuffer&& other) noexcept : 
    mDataType(other.mDataType),
    mCount(other.mCount),
    mData(other.mData),
    mSize(other.mSize),
    mStructStride(other.mStructStride)
{
    other.mData = nullptr;
}

DataBuffer& DataBuffer::operator=(DataBuffer&& other) noexcept
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