#ifdef MATRIX_H
#define MATRIX_H

#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

template<class T>
class Matrix {

protected:
    vector<vector<T>> mat;
    unsigned rows;
    unsigned cols;
public:
    Matrix() : rows{ 0 }, cols{ 0 } {}

    Matrix(unsigned _rows, unsigned _cols, const T& initial) :
        rows{ _rows },
        cols{ _cols },
        mat{ _rows } {
        for(unsigned i = 0; i < _rows; i++)
            mat[i].resize(_cols, initial);
    }

    Matrix(unsigned _rows, unsigned _cols) :
        rows{ _rows },
        cols{ _cols },
        mat{ _rows } {
        for(unsigned i = 0; i < _rows; i++)
            mat[i].resize(_cols);
    }

    Matrix(const Matrix& rhs) {
        // deep copy usando la copia dei vector
        mat = rhs;
        rows = rhs.rows;
        cols = rhs.cols;
    }


    unsigned csize() const { return rows; }
    unsigned rsize() const { return cols; }

    void resize(unsigned _rows, unsigned _cols) {
        mat.resize(_rows);
        for(unsigned i = 0; i < _rows; i++)
            mat[i].resize(_cols);
        rows = _rows;
        cols = _cols;
    }

    virtual T& operator()(unsigned row, unsigned col) {
        assert(row < rows&& col < cols);
        return mat[row][col];
    }

    // void print() {
    //     for(auto row : mat)
    //         for(auto x : row)
    //             cout << x << " ";
    //     cout << endl;
    // }

    void print() {
        for(unsigned i = 0; i < rows; ++i)
            for(unsigned j = 0; j < cols; ++j)
                cout << (*this)(i, j) << " ";
        cout << endl;
    }
};

#endif 
