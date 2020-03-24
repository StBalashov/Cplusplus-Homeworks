#include <iostream>

#include "Matrix.h"

int main() {

    Matrix a(2, 2);
    Matrix b(2, 2);

    int dataA[] = {1, 2, 3, 4};
    int dataB[] = {4, 3, 2, 1};

    a.setData(dataA);
    b.setData(dataB);

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    a += b;
    b *= b;

    std::cout << a << std::endl;
    std::cout << b << std::endl;

    Matrix c = a;

    std::cout << c << std::endl;
    std::cout << (a == c) << std::endl;
    std::cout << a * c << std::endl;
    std::cout << (a, c) << std::endl;

    return 0;
}