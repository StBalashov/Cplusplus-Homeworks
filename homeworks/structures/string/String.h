//
// Created by Кирилл Чулков on 25/10/2018.
//

#pragma once

#include <cstddef>
#include <iostream>

class String {
public:

    String();
    String(char* cString);
    String(size_t n, char c);
    ~String();

    String(const String& other);
    String& operator=(const String& other);

    String& append(const String& other);
    size_t length() const;

    friend std::istream& operator>>(std::istream& is, String& item);
    friend std::ostream& operator<<(std::ostream& os, const String& item);

private:

    size_t mSize;
    char* mString;

    void swap(String& other);
};

