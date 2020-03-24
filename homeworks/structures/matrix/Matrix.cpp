//
// Created by Кирилл Чулков on 12/11/2018.
//

#include <iostream>
#include <algorithm>

#include "Matrix.h"

Matrix::Matrix(size_t sizeN, size_t sizeM) : mSizeN(sizeN), mSizeM(sizeM), mData(new int[mSizeN * mSizeM]) {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] = 0;
        }
    }
}

Matrix::~Matrix() {
    delete[] mData;
}

Matrix::operator bool() const {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            if (mData[i * mSizeM + j] < 0) {
                return false;
            }
        }
    }
    return true;
}

void Matrix::swap(Matrix& other) {
    std::swap(mSizeN, other.mSizeN);
    std::swap(mSizeM, other.mSizeM);
    std::swap(mData, other.mData);
}

Matrix::Matrix(const Matrix& other) : mSizeN(other.mSizeN), mSizeM(other.mSizeM), mData(new int[mSizeN * mSizeM]) {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] = other.mData[i * mSizeM + j];
        }
    }
}

Matrix& Matrix::operator=(const Matrix& other) {
    if (this != &other) {
        Matrix(other).swap(*this);
    }
    return *this;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] += other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] += other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    if (mSizeM != other.mSizeN) {
        throw /* Exception*/ ;
    }
    Matrix result = *this;
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            for (int k = 0; k < mSizeM; ++k) {
                result.mData[i * mSizeM + j] += mData[i * mSizeM + k] * other.mData[k * mSizeM + j];
            }
        }
    }
    *this = result;
    return *this;
}

Matrix& Matrix::operator/=(int divider) {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] /= divider;
        }
    }
    return *this;
}

Matrix& Matrix::operator%=(int divider) {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] /= divider;
        }
    }
    return *this;
}

Matrix& Matrix::operator&=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] &= other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator|=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] |= other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator^=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] ^= other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator<<=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] <<= other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator>>=(const Matrix& other) {
    if (mSizeN != other.mSizeN || mSizeM != other.mSizeM) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] >>= other.mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix& Matrix::operator+() {
    return *this;
}

Matrix& Matrix::operator-() {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] *= -1;
        }
    }
    return *this;
}

Matrix& Matrix::operator++() {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            ++mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    Matrix result = *this;
    ++(*this);
    return result;
}

Matrix& Matrix::operator--() {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            --mData[i * mSizeM + j];
        }
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    Matrix result = *this;
    --(*this);
    return result;
}

bool Matrix::operator!() {
    for (int i = 0; i < mSizeN; ++i) {
        mData[i * mSizeM + i] = 0;
    }
    return *this;
}

Matrix& Matrix::operator~() {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            if (i != j) {
                mData[i * mSizeM + i] = 0;
            }
        }
    }
    return *this;
}

int Matrix::operator[](int index) const {
    return mData[index * mSizeM + index];
}

const int& Matrix::operator()(int i, int j) const {
    return mData[i * mSizeM + j];
}

Matrix Matrix::operator*() {
    return *this;
}

Matrix Matrix::operator/(int divider) {
    Matrix result = *this;
    result /= divider;
    return result;
}

Matrix Matrix::operator%(int divider) {
    Matrix result = *this;
    result %= divider;
    return result;
}

int Matrix::getSizeN() const {
    return mSizeN;
}

int Matrix::getSizeM() const {
    return mSizeM;
}

void Matrix::setData(int data[]) {
    for (int i = 0; i < mSizeN; ++i) {
        for (int j = 0; j < mSizeM; ++j) {
            mData[i * mSizeM + j] = data[i * mSizeM + j];
        }
    }
}

Matrix operator+(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result += second;
    return result;
}

Matrix operator-(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result -= second;
    return result;
}

Matrix operator*(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result *= second;
    return result;
}

Matrix operator&(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result &= second;
    return result;
}

Matrix operator|(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result |= second;
    return result;
}

Matrix operator^(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result ^= second;
    return result;
}

Matrix operator&&(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result = result * second * second;
    return result;
}

Matrix operator||(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result = result - second - second;
    return result;
}

Matrix operator<<(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result <<= second;
    return result;
}

Matrix operator>>(const Matrix& first, const Matrix& second) {
    Matrix result = first;
    result >>= second;
    return result;
}

bool operator==(const Matrix& first, const Matrix& second) {
    if (first.getSizeN() != second.getSizeN() || first.getSizeM() != second.getSizeM()) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < first.getSizeN(); ++i) {
        for (int j = 0; j < first.getSizeM(); ++j) {
            if (first(i, j) != second(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix& first, const Matrix& second) {
    return !(first == second);
}

bool operator<(const Matrix& first, const Matrix& second) {
    if (first.getSizeN() != second.getSizeN() || first.getSizeM() != second.getSizeM()) {
        throw /* Exception*/ ;
    }
    for (int i = 0; i < first.getSizeN(); ++i) {
        for (int j = 0; j < first.getSizeM(); ++j) {
            if (first(i, j) > second(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool operator>(const Matrix& first, const Matrix& second) {
    return second < first;
}

bool operator<=(const Matrix& first, const Matrix& second) {
    return !(second < first);
}

bool operator>=(const Matrix& first, const Matrix& second) {
    return !(first < second);
}

Matrix operator,(const Matrix& first, const Matrix& second) {
    return first * second + second * first;
}

std::ostream& operator<<(std::ostream& os, const Matrix& item) {
    for (int i = 0; i < item.getSizeN(); ++i) {
        for (int j = 0; j < item.getSizeM(); ++j) {
            std::cout << item(i, j)<< " ";
        }
        std::cout << std::endl;
    }
    return os;
}


