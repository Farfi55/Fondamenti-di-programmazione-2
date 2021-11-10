#include "Matrix.cpp"

template<class T >
class SymmetricMatrix : public Matrix<T> {
private:
    using Matrix<T>::rows;
    using Matrix<T>::cols;
    using Matrix<T>::mat;

    // altrenative
    // matrix<T>::rows ogni volta  oppure
    // this->rows

public:
    SymmetricMatrix() {}
    SymmetricMatrix(unsigned _rows, const T& initial) {
        mat.resize(_rows);
        for(int i = 0; i < _rows; i++) {
            mat[i].resize(i + 1, initial);
        }
        cols = _rows;
        rows = _rows;
    }

    SymmetricMatrix(const SymmetricMatrix& smat) {}

    override T& operator()(unsigned row, unsigned col) {
        assert(row < rows&& col < cols);
        if(i < j) return (*this)(j, i);
        else return (*this)(i, j);
    }



};
