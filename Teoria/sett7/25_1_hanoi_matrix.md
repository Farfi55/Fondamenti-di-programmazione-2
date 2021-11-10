# 10/11/2021

## Esercizio 1

#### Torri di Hanoi con gli stack

#### Codice printStack disponibile [qui](https://github.com/Farfi55/Fondamenti-di-programmazione-2/blob/master/Teoria/sett7/printStack.cpp)
```C++
void TowersOfHanoi(int n, stack<int>& from_rod,
  stack<int>& to_rod, stack<int>& aux_rod,
    char f, char T, char a) {
  if (n == 1) {
    to_rod.push(from_rod.top());
    from_rod.pop();
    print_rods_in_order(from_rod, to_rod, aux_rod, f, t, a);
    return;
  }
  TowersOfHanoi(n-1, from_rod, aux_rod, to_rod, f, a, t);
  to_rod.push(from_rod.top());
  from_rod.pop();
  print_rods_in_order(from_rod, to_rod, aux_rod, f, t, a);
  TowersOfHanoi(n-1, aux_rod, to_rod, from_rod, a, t, f);
}

void print_rods_in_order(stack<int>& from_rod,
  stack<int>& to_rod, stack<int>& aux_rod,
    char f, char T, char a) {
  if (f == "A") 
    printStack(from_rod);
  else if (t == "A") 
    printStack(to_rod);
  else if (a == "A") 
    printStack(aux_rod);
  if (f == "B")
    printStack(from_rod);
  else if (t == "B") 
    printStack(to_rod);
  else if (a == "B") 
    printStack(aux_rod);
  if (f == "C")
    printStack(from_rod);
  else if (t == "C") 
    printStack(to_rod);
  else if (a == "C") 
    printStack(aux_rod);
}
```
## Classe matrice e matrice simmetrica

Ogni vector contiene dentro un altro vector di int: ``` vector<vector<int>>```

Flaws (Classe matrice):
- Ogni vector può avere size differente dall'altro, non avendo così una "matrice" omogenea, se non specificato diversamente.

Dati da ricordare (in `unsigned`, per classe matrice):
- Nr. di righe (`rows`)
- Nr. di colonne (`cols`)

Dati da ricordare (in `unsigned`, per classe matrice simmetrica):
- Nr. di righe (`rows`)
- Per le colonne, verrà utilizzato n+1 (`rows` + 1)

Codice:

```C++
#include <iostream>
#include <vector>
#include .....
Template<class T>
class Matrix {
  protected:
    /* Da standard, ogni unsigned è considerato unsigned int se non specificato diversamente */
    unsigned cols, rows;
    vector<vector<int>> mat;
  public:
    Matrix():rows(0), cols(0) {};
    Matrix(unsigned _rows, unsigned _cols, const T& initial) {
      mat.resize(_rows);
      for(unsigned i=0; i<mat.size(); i++) {
        mat[i].resize(_cols, initial);
      }
      rows = _rows;
      cols = _cols;
    }
    Matrix(const Matrix<T>& rhs) {
      mat = rhs;
      rows = rhs.rows;
      cols = rhs.cols;
    }
    unsigned getcolsSize() const { return cols; }
    unsigned getrowsSize() const { return rows; }
    
    void resize(unsigned _rows, unsigned _cols) {
      mat.resize(_rows);
      for(unsigned i=0; i<mat.size(); i++) {
        mat[i].resize(_cols);
      }
      rows = _rows;
      cols = _cols;
    }

    T& operator()(unsigned row, unsigned col) { //m(i, j) = num.       
      assert(row < rows && col < cols)
      /* mat = vector<vector<T>>, mat[row] = vector<T>, mat[row][col] = T */
      return mat[row][col]; 
    }

    void print() {
      for(unsigned int i=0; i<rows; i++) {
        for(unsigned int j=0; j<cols; j++) {
          /* Si usa (*this) per evitare di riscrivere mat */
          cout<<(*this)(i, j)<<" ";
        }
        cout<<endl;
      }
    }
}

Template <class T>
class SymmethricMatrix : public Matrix<T> {
  using Matrix<T>::rows;
  using Matrix<T>::cols;
  using Matrix<T>::mat;
  public:
    SymmethricMatrix(unsigned _rows, const T& initial) {
      mat.resize(_rows);
      for(unsigned i=0; i<mat.size(); i++) {
        mat[i].resize(i+1, initial);
      }
      rows = _rows;
      cols = _cols;
    }
    T& operator()(unsigned row, unsigned col) {
      assert(row < rows && col < cols);
      if (row < col) return mat[col][row];
      return mat[row][col];
    }
}

int main() {
  Matrix<int> m1(3, 5, 5);
  m1.print();
  Matrix<int> m2(3, 5);
  m2.print();
  m1.resize(100, 100);
  SymmethricMatrix<int> m5(5, 1);
  m5(0, 4) = 32;
}
```
