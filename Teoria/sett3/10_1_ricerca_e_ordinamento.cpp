#include <iostream>
using namespace std;

bool ricercaLineare(int insieme[], int x, int n) {
    bool trovato = false;
    // for (int i = 0; i < n; i++)	// O(n) sia C.M. che C.P.
    for (int i = 0; i < n && !trovato; i++)  // Andiamo a vedere tutti i casi *
        if (insieme[i] == x) trovato == true;
    return trovato;
}

/*
        caso 1: x non c'è ----> O(n)
        caso 2: x è l'ultimo elemento --> O(n)
        caso 3: x è il primo elemento --> O(1)
        caso 4: x è in mezzo -----> ?


        caso migliore: min(c1, c2, c3, c4) ----> O(1)
        caso peggiore: max(c1, c2, c3, c4) ----> O(n)

        _______________________
*/

// l'insime è ordinato in modo crescente

bool ricercaLineareOrd(int insieme[], int x, int n) {
    bool trovato = false;

    for (int i = 0; i < n && !trovato && x >= insieme[i];
         i++)  // cambia solo il caso 1
        if (insieme[i] == x) trovato == true;
    return trovato;
}

// Ricerca binaria
bool ricercaBinariaRic(int v[], int x, int n, int left, int right) {
    if (left >= right)
        return (left == right && v[left] == x);
    else {
        int mid = (left + right) / 2;

        if (v[mid] < x)
            left = mid + 1;
        else if (v[mid] > x)
            right = mid - 1;
        else  // v[medio] == x
            left = right = mid;
        return ricercaBinariaRic(v[], x, n, left, right);
    }
}
// C.P. ----> O(log_2(n))
// C.M. ----> O(1)

bool ricercaBinaria(int v[], int x, int n) {
    int left = 0, right = n, mid = (left + right) / 2;

    while (left != right) {
        if (x == v[mid])
            return true;
        else if (x < v[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return false;
}

int main() {
    const int n = 15;
    int v[n] = {1, 3, 6, 7, 8, 9, 11, 15, 16, 18, 20, 21, 24, 27, 30};
    int x;
    cin >> x;

    ricercaBinariaRic(v[], );
    return 0;
}
