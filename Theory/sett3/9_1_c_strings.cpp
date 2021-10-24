#include <iostream>
using namespace std;

char str[10] = {'c', '+', '+', '\0'};

cin >> str;
cout << str;

char str[10] = {'c', '+', '+'};
cout << str; //output indefinito

#include <cstring>

strlen(p); // restituisce la lunghezza di p

strcmp(p1, p2); // confronta p1 e p2
// p1 == p2: 0
// p1 > p2: valore positivo
// p1 < p2: valore negativo

strcat(p1, p2); // appende il contenuto di p2 su p1, risultato in p1
// attenzione alla dimensione di p1

strcpy(p1, p2); // copia p2 in p1
