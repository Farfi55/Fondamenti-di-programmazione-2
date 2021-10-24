//leggere un seq. di N cifre binarie, con N letto da input.
// individuare la lunghezza massima della sottosequenza costituita da cifre uguali

#include <iostream>

using namespace std;


int main()
{
    int N;
    int lung = 0, lung_max = 0;
    int cifra, cifra_max, ultima;

    cout << "inserisci N: ";
    cin >> N;

    if( N > 0)
    {
        cout << "inserisci numero: ";
        cin >> ultima;
        lung = 1, lung_max = 1;
        cifra_max = ultima;
        N--;

        while (N > 0){
            cout << "inserisci numero: ";
            cin >> cifra;
            
            if (cifra == ultima){
                lung++;
                if(lung > lung_max)
                {
                    lung_max = lung;
                    cifra_max = cifra;
                }

            }
            else{
                lung = 1;
                ultima = cifra;
            }

            N--;
        }
    }

    cout << "La lunghezza massima e': " << lung_max << endl;    
    if(lung_max > 0)
        cout << "La cifra della lunghezza massima e': " << cifra_max << endl; 

    return 0;
}