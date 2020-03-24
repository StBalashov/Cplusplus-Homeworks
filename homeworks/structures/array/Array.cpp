//
// Created by Кирилл Чулков on 11/11/2018.
//

#include "Array.h"

template <typename T>
Array<T>::Array(size_t size, const T& value) : mSize(size) {
    mData = static_cast<T*> (operator new(mSize * sizeof(T)));
    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) T(value);
    }
}

template <typename T>
Array<T>::Array() : mSize(0), mData(nullptr) {}

template <typename T>
Array<T>::Array(const Array& array) {
    mSize = array.size();
    mData = static_cast<T*> (operator new(mSize * sizeof(T)));
    for (size_t i = 0; i < mSize; ++i) {
        new(mData + i) T(array[i]);
    }
}

template <typename T>
Array<T>::~Array() {
    for (size_t i = 0; i < mSize; ++i) {
        mData[i].~T();
    }
    operator delete(mData);
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& array) {
    if (this->mData != array.mData) {
        for (size_t i = 0; i < mSize; ++i) {
            mData[i].~T();
        }
        operator delete(mData);
        mSize = array.size();
        mData = static_cast<T*> (operator new(mSize * sizeof(T)));
        for (size_t i = 0; i < mSize; ++i) {
            new(mData + i) T(array[i]);
        }
    }
    return *this;
}

template <typename T>
size_t Array<T>::size() const {
    return mSize;
}

template <typename T>
T& Array<T>::operator[](size_t i) {
    return mData[i];
}

template <typename T>
const T& Array<T>::operator[](size_t i) const {
    return mData[i];
}
