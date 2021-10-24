//Calcolo della potenza tramite funzione
//Scrivere una funzione che ricevuti due numeri a e b calcoli la potenza a^b

#include <iostream>
using namespace std;

int potenza(int a, int b);

int main(){
    int a, b;
    cout << "Inserisci due numeri: ";
    cin >> a >> b;
    
    int ris = potenza(a, b);
    cout << a << "^" << b << ": " << ris;

    return 0;
}


int potenza(int a, int b){
    int ris = 1;

    for (int i = 0; i < b; i++) ris *= a;
    return ris;
}
