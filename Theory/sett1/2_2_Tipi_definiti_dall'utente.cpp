// TIPI DEFINITI DALL'UTENTE

//strutture dati semplici
struct punto {
    int x;
    int y;
}; // ";" alla fine


#include <iostream>
#include <cmath> // per le funzioni matematiche come sqrt
using namespace std;

int main(){
    punto p1, p2;
    double distanza;

    // per accedere ai membri della struttura ddati bisogna utilizzare la notazione
    // p1.x o p1.y
    

    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;

    distanza = sqrt( (p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y) )

    cout << "La distanza è: " << distanza << endl;


    punto *pp1 = &p1;
    
    // dereferenziazione
    
    // oggetto ti tipo Punto
    cout << *pp1 << endl;

    // () considera l'oggetto intero e prendi il valore di int x
    cout << (*pp1).x << endl;

    // stessa cosa ma più leggibile
    cout << pp1->x << endl;



    
    return 0;
}




