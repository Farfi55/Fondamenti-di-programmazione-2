#include <iostream>
using namespace std;

//TIPI COMPOSTI
/*
    - Riferimenti
    - Puntatori
*/


//Riferimenti
int ival = 1024;

int &refval = ival;  // è un puntatore alla stessa cella di memoria di ival
// & significa che la variabile è unn riferimento
int &refval2; // ERRORE! non si puù definire un puntatore senza assegnazione

refval = 2; // ival = 2

int ii = refval; // ii = 2 (in un altro)



//Puntatori
int *ip1, *ip2; // puntatori di tipo intero non inizializzati
double dp, *dp2; // dp = variabile double, dp2 = puntatore di tipo double 


//esempio
int ival = 42;
int *p = &ival; // qui "&" restituisce l'indirizzo di memoria di ival


// indirizzo| conten| nome
// -------------------------
// ffx02    | 42    | ival
//          |       |
//          | ffx02 | p
// -------------------------


// per stampare il contenuto in memoria nella posizione indicata da p
cout  << *p << endl; // 42

// per stampare l'indirizzo contenuto in p
cout  << p << endl; // ffx02



//STATI POSSIBILI
/*
    - puntatore ad un oggetto

    - puntatore alla locazione di memoria immediatamente successiva ad un oggetto

    - essere nullo   */ 
        int* p2 = 0
        int* p3 = nullptr;
        int* p4 = NULL; // bisogna includere <cstdlib>

//  - non essere valido 


// i = variabile con valore 1024
// p5 = puntatore all'indirizzo di i
// r = riferimento a i
int i = 1024, *p5 = &i, &r = i;

// vedremo più avanti
char* c;













