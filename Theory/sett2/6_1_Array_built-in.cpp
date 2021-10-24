// Array Built-in

#include <iostream> 

using namespace std;

// TIPO_BASE NOME [DIMENSIONE];

int a1[10];
// il nome in cpp viene interpretato come l'indirizzo della prima cella di memoria

const int dim = 10;
int a2[dim];  

// questo si può fare nelle ultime versioni di cpp 
int dim2;
cin >> dim2;
int a[dim2]; 

// una volta stabilito la dimensione dell'array, essa non può cambiare

//Per inizializzare:
int s2 = 3;
int ia1[s2] = {0, 1, 2};
int a2[] = {0, 1, 2};
int a3[5] = {0, 1, 2}; // a3 = {0, 1, 2, 0, 0}

#if 0
int a5[2] = {0, 1, 2}; // ERRORE

// Non si può leggere o scrivere un array per intero

cin >> a; // NO

// unica eccezione per gli array di char
int a[] = {0,1,2};
int a2[] = a; // ERRORE
a2 = a; // ERRORE
#endif

// accesso agli elementi 
// struttura ad "Accesso diretto"

// indice primo elemento 0
int dim6 = 10;
int a6[dim];
a6[0]; // primo elemento
a6[dim-1]; // ultimo elemento









