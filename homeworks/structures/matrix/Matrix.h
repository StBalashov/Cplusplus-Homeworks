//
// Created by Кирилл Чулков on 12/11/2018.
//

#ifndef MATRIX_MATRIX_H
#define MATRIX_MATRIX_H


#include <cstddef>
#include <iostream>

class Matrix {
public:

    Matrix(size_t sizeN, size_t sizeM);
    ~Matrix();
    operator bool() const;

    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix& other);

    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator/=(int divider);
    Matrix& operator%=(int divider);

    Matrix& operator&=(const Matrix& other);
    Matrix& operator|=(const Matrix& other);
    Matrix& operator^=(const Matrix& other);

    Matrix& operator<<=(const Matrix& other);
    Matrix& operator>>=(const Matrix& other);

    Matrix operator/(int divider);
    Matrix operator%(int divider);

    Matrix& operator+();
    Matrix& operator-();

    Matrix& operator++();
    Matrix operator++(int);
    Matrix& operator--();
    Matrix operator--(int);

    bool operator!();
    Matrix& operator~();

    int operator[](int index) const;

    const int& operator()(int i, int j) const;

    Matrix operator*();

    int getSizeN() const;
    int getSizeM() const;

    void setData(int data[]);

private:
    size_t mSizeN;
    size_t mSizeM;
    int* mData;

    void swap(Matrix& other);

};

Matrix operator+(const Matrix& first, const Matrix& second);
Matrix operator-(const Matrix& first, const Matrix& second);
Matrix operator*(const Matrix& first, const Matrix& second);

Matrix operator&&(const Matrix& first, const Matrix& second);
Matrix operator||(const Matrix& first, const Matrix& second);

Matrix operator&(const Matrix& first, const Matrix& second);
Matrix operator|(const Matrix& first, const Matrix& second);
Matrix operator^(const Matrix& first, const Matrix& second);

Matrix operator<<(const Matrix& first, const Matrix& second);
Matrix operator>>(const Matrix& first, const Matrix& second);

bool operator==(const Matrix& first, const Matrix& second);
bool operator!=(const Matrix& first, const Matrix& second);
bool operator<(const Matrix& first, const Matrix& second);
bool operator>(const Matrix& first, const Matrix& second);
bool operator<=(const Matrix& first, const Matrix& second);
bool operator>=(const Matrix& first, const Matrix& second);

Matrix operator,(const Matrix& first, const Matrix& second);

std::istream& operator>>(std::istream& is, Matrix& item);
std::ostream& operator<<(std::ostream& os, const Matrix& item);


#endif //MATRIX_MATRIX_H
