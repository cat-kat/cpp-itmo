#ifndef HW7_ARRAY_HPP
#define HW7_ARRAY_HPP

#include "Array.h"

template<class Type>
Array<Type>::Array() : mData(nullptr), mSize(0) {}

template<class Type>
Array<Type>::Array(size_t size, const Type& value) : mSize(size) {
    mData = new unsigned char[mSize * sizeof(Type)];
    Type* ptr = (Type*) mData;
    for (size_t i = 0; i < mSize; ++i) {
        new(ptr + i) Type(value);
    }
}

template<class Type>
Array<Type>::Array(const Array<Type>& other) : mSize(other.mSize) {
    mData = new unsigned char[mSize * sizeof(Type)];
    Type* ptr = (Type*) mData;
    for (size_t i = 0; i < mSize; ++i) {
        new(ptr + i) Type(other[i]);
    }
}

template<class Type>
Array<Type>::~Array() {
    Type* ptr = (Type*) mData;
    for (size_t i = 0; i < mSize; ++i) {
        ptr[i].~Type();
    }
    delete[] mData;
}

template<class Type>
Array<Type>& Array<Type>::operator=(const Array& other) {
    if (this != &other) {
        Array(other).swap(*this);
    }
    return *this;
}

template<class Type>
Type& Array<Type>::operator[](size_t i) {
    if (mSize <= i || i < 0) throw "Going out of range";
    Type* ptr = (Type*) mData;
    return *(ptr + i);
}

template<class Type>
const Type& Array<Type>::operator[](size_t i) const {
    if (mSize <= i || i < 0) throw "Going out of range";
    Type* ptr = (Type*) mData;
    return *(ptr + i);
}


template<class Type>
void Array<Type>::swap(Array<Type>& other) {
    std::swap(mData, other.mData);
    std::swap(mSize, other.mSize);
}

#endif