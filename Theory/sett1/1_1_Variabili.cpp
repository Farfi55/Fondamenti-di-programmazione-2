#include <iostream>

using namespace std;
int main()
{

    // questo è un commento

    // VARIABILI:
    // TIPO_VARIALIBE NOME_VARIABILE
    // Tipi (base):

    bool b; // true o false
    char c; // singolo valore alfanumerico

    int i;           // numero intero (4 byte)
    short sh;        // numero intero (2byte)
    long lo;         // numero intero (8byte)
    unsigned int ui; // numero intero senza segno ()

    // numeri a virgola mobile
    float f;
    double d;

    // input:  >>
    // output: <<

    // inizializzare ogni variabile
    int i1;         // non inizializata EVITARE
    int i2 = 0;     // inizializata esplicitamente a 0
    bool b = false; // inizializata esplicitamente a false

    int a = 0;
    int a = {0}; // inizializzazione a lista (LIST INIZIALIZZATION)
    int a{0};    // stessa cosa
    int a(0);    // inizializzazione di un oggetto

    // con le parentesi graffe
    long double ld = 3.14159265536;
    int a{ld};         // ERRORE, la parentesi graffa NON AMMETTE perdita di informazioni
    int c(ld), d = ld; // valore troncato, ma nessun errore

    // assegnare a tipi diversi
    bool b = 42;  // false = 0, qualsiasi altro valore = 1 -> b sarà true
    int i = b;    // i contiene 1
    int i = 3.14; // i conterrà solo 3
    float pi = i; //pi conterrà 3.0f

    // tipo auto
    // auto i; // ERRORE
    auto i = 0; // auto prenderà il tipo di int
    float val1 = 4.1, val2 = 3.5;
    auto item = val1 + val2; // auto sceglierà in base al tipo di val1 e val2

    // visibilità (vedi "2 scope.cpp")

    // variabili constanti
    const int constvar = 35;

    //Caratteri speciali
    char ACapo = '\n';
    char Intabulare = '\t';

    // Incrementazione
    int i = 1;
    int j = i++; // j = 1 dopo di che i = 2
    j = ++i;     // i incrementato a 3, j = 3

    int sum = 6;
    sum += i; // stesso di sum = sum + i

    bool b1 = true;
    bool b2 = !b1; // ! inverte il valore da false a true e viceversa

    // CONFRONTI
    (1 == 1); //  è uguale?
    (1 != 2); //  è diverso?
              // &  AND senza short circuit
              // || OR  con short circuit
              // && AND con short circuit
    return 0;
}