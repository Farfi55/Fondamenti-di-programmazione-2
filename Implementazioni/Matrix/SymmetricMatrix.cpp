#ifndef SYMMETRIC_MATRIX_H
#define SYMMETRIC_MATRIX_H

#include <cassert>
#include "Matrix.cpp"

template<class T>
class SymmetricMatrix : public Matrix<T> {
private:
    using Matrix<T>::rows;
    using Matrix<T>::cols;
    using Matrix<T>::mat;

    // altrenative
    // matrix<T>::rows ogni volta  oppure
    // this->rows

public:
    SymmetricMatrix() : rows{ 0 }, cols{ 0 } {}

    SymmetricMatrix(unsigned _rows, const T& initial) {
        mat.resize(_rows);
        for(int i = 0; i < _rows; i++) {
            mat[i].resize(i + 1, initial);
        }
        cols = _rows;
        rows = _rows;
    }

    SymmetricMatrix(const SymmetricMatrix& sm) {
        mat = sm.mat;
        rows = sm.rows;
        cols = sm.cols;
    }

    T& operator()(unsigned row, unsigned col) {
        assert(row < rows&& col < cols);
        if(row < col) return (*this)(col, row);
        else return (*this)(row, col);
    }



};

#endif
