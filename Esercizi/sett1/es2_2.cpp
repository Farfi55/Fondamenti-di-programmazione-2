/*
Definire una funzione che calcola la distanza tra due punti (struct punto)
*/

#include <iostream>
#include <cmath>
#include "../theory/2 punto.h"


using namespace std;

double distanza(punto p1, punto p2);

int main(){
    punto p1, p2;
    cout << "inserisci coordinate primo punto: \nx: ";
    cin >> p1.x;
    cout << "y: "; 
    cin >> p1.y;

    cout << "inserisci coordinate secondo punto: \nx: ";
    cin >> p2.x;
    cout << "y: "; 
    cin >> p2.y;

    cout << "La distanza tra i due punti è: " << distanza(p1, p2) << endl;

    getchar();
    return 0;
}


double distanza(punto p1, punto p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}