//data una sequenza di sottosequenze di numeri interi positivi separate da uno 0 
// la sequenza è terminata da una coppia di 0


#include <iostream>

using namespace std;


int main()
{
    int n, prec, somma = 0;

    cout << "inserisci un numero: ";
    cin >> n;
    somma = n;

    do{
        prec = n;
        cout << "inserisci un numero: ";
        cin >> n;
        somma += n;

        if(n == 0){
            if(prec != 0)
                cout << "La somma della sottosequenza e': "<< somma << endl;
            somma = 0;
        }       

    }while(prec != 0 || n != 0);

    return 0;
}
