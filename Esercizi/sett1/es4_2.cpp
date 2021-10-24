/*
ESERCIZIO INIZIALE SULLE FUNZIONI
Scrivere una funzione f che ricevuti due interi x e y restituisce il
risultato dell'operazione (x+x) + (y*y)
*/

#include <iostream>
using namespace std;

int f(int& x, int& y);


int main(){
    int a = 4, b = 3, c = 0;

    cout << "Prima di eseguire f: a = " << a << ", b = " << b << ", c = " << c << endl;

    c = f(a, b);

    cout << "Dopo l'eseczione di f: a = " << a << ", b = " << b << ", c = " << c << endl;

    c = f(a, b);

    cout << "Dopo la seconda eseczione di f: a = " << a << ", b = " << b << ", c = " << c << endl;

    return 0;
}


int f(int& x, int& y){
    x = x + x;
    y = y * y;
    return x + y;
    //return (x+x) + (y*y);
}