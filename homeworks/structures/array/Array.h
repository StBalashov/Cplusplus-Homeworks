
#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H


#include <cstddef>

template <typename T>
class Array {
public:
    explicit Array(size_t size, const T& value = T());

    Array();

    Array(const Array& array);

    ~Array();

    Array<T>& operator=(const Array& array);

    size_t size() const;

    T& operator[](size_t i);

    const T& operator[](size_t i) const;

private:
    size_t mSize;
    T* mData;
};


#endif //ARRAY_ARRAY_H
