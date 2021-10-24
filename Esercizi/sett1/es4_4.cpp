//ISTOGRAMMI

//stampa degli istogrammi relativi ad una sequenza di numeri terminata da 
// un numero negativo 
/*
    INPUT:  3 4 1 0 2 -1
    OUTPUT: 
    ***
    ****
    *

    **
*/

#include <iostream>

using namespace std;

void stampaIstogramma(int x);

int main(){

    int x;
    
    cin >> x;
    while(x >= 0){
        stampaIstogramma(x);
        cin >> x;
    }

    
    return 0;
}

void stampaIstogramma(int x){
    if (x < 0) return;

    for (int i = 0; i < x; i++)
        cout << '*';
    cout << endl;
}
