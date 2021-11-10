#include "Matrix.cpp"
#include "SymmetricMatrix.cpp"

int main(int argc, char const* argv[])
{
    // matrice 3x5 piena di 5
    Matrix<int> m1(3, 5, 5);
    m1.print();

    Matrix<int> m2(3, 5);
    m2.print();

    m2.resize(100, 100);

    SymmetricMatrix<int> ms(5, 1);
    ms(0, 4) = 32;

    m2.print();


    return 0;
}
