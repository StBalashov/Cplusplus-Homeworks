//
// Created by Кирилл Чулков on 25/10/2018.
//

#include <cstring>
#include <algorithm>

#include "String.h"

String::String() : mSize(0), mString(new char[1]) {
    mString[0] = '\0';
}

String::String(char* cString) : mSize(strlen(cString)), mString(new char[mSize + 1]) {
    strcpy(mString, cString);
}

String::String(size_t n, char c) : mSize(n), mString(new char[mSize + 1]) {
    for (size_t i = 0; i < mSize; ++i) {
        mString[i] = c;
    }
    mString[mSize] = '\0';
}

String::String(const String& other) : mSize(other.mSize), mString(new char[mSize + 1]) {
    strcpy(mString, other.mString);
}

String::~String() {
    delete[] mString;
}

void String::swap(String& other) {
    std::swap(mString, other.mString);
    std::swap(mSize, other.mSize);
}

String& String::operator=(const String& other) {
    if (this != &other) {
        String(other).swap(*this);
    }
    return *this;
}

String& String::append(const String& other) {
    mSize += other.mSize;
    char* m = new char[mSize + 1];
    strcat(strcpy(m, mString), other.mString);
    delete[] mString;
    mString = m;
    return *this;
}

size_t String::length() const {
    return mSize;
}

std::istream& operator>>(std::istream& is, String& item) {
    String string;
    char ch;
    while (is.get(ch)) {
        string.append(&ch);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const String& item) {
    for (int i = 0; i < item.length(); ++i) {
        os << item.mString[i];
    }
    return os;
}
