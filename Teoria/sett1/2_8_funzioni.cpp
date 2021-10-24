#if 0
/*
    RECORD DI ATTIVAZIONE
            |                   | 
    --------------------------------------------
    val    5|parametro1         | 
            |parametro2         |
            |variabile1         | 
            |variabile2         |
            |valore di ritorno  |
    -------------------------------------------
*/


int f2(){} // ok
int f3(int v1, v2){} // ERRORE, va specificato il tuppo di v2
int f4(int v1, int v2){} // ok

//tipi di ritorno
/*
    - qualsiasi tipi di base
    - tipi derivati
    - void (cioè non restituisce nulla)
        richiede in ogni caso che ci sia un return
*/


if(cond){  } // questo percorno non include un return, è quindi un errore
else{ return; }

#endif


#include <iostream>
using namespace std;

//PASSAGGIO DEI PARAMETRI
/*
    - per valore 
    - per riferimento
    (sia costante che non)
*/


// esempio passaggio per valore
// creo una copia del valore int passato alla funzione
int factVal(int val){
    int ret = 1;
    while (val > 1) ret *= val--;
    return ret;
    
}


// esempio passaggio per riferimento
// prendo esattamente la variabile passata
int factRef(int &val){ 
    int ret = 1;
    while (val > 1) ret *= val--;
    return ret;
}

#if 0
// passaggop per riferimento costante
int factRefConst(const int &val){
    int ret = 1;
    while (val > 1) ret *= val--;
    return ret;
}
#endif

#include "2_punto.h"
void f5(punto p){} // crea una copia in memoria
void f6(const punto& p){} // utilizza la stessa variabile senza allocare memoria



int main(){
    int x;
    std::cin >> x;
    std::cout << "fattoriale con passaggio a valore: " << factVal(x) << ", x: " << x<< std::endl;
    std::cout << "fattoriale con passaggio a riferimento: " << factRef(x) << ", x: " << x << std::endl;
    std::cout << "fattoriale con passaggio a valore: " << factVal(x) << ", x: " << x<< std::endl;

}