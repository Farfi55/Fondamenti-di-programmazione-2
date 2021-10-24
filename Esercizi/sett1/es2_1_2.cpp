#include <iostream>

using namespace std;


bool ePrimo(int);


int main(){

    int numero;
    while(cin >> numero)
    {
        if(ePrimo(numero))
            cout << numero << " e' primo\n";
        else
            cout << numero << " non è primo\n";
    }
}


bool ePrimo(int n){
    bool primo = true;

    for (int k = 0; k < n/2 && primo; k--){
        if (n%k == 0)
            primo = false;
    }
    return primo;
}