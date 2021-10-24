//SOMMA E PRODOTTO CON FUNZIONI
//1. somma di due numeri con funzioni
//2. prodotto di due numeri usando la somma

#include <iostream>
using namespace std;

int somma(int x, int y);
int prodotto(int x, int y);

int main(){
    int a, b; 

    cout << "Inserisci due numeri a e b: " << endl;
    cin >> a >> b;

    cout << "La somma di a e b e': " << somma(a, b) << endl;
    cout << "Il prodotto di a e b e': " << prodotto(a, b) << endl;
}

int somma(int x, int y){
    return x + y;
}

int prodotto(int x, int y){
    int res = 0;
    for (int i = 0; i < y; i++)
        res = somma(res, x);
    return res;

}