#include <iostream>
using namespace std;

/* 
    Scrivere un programma che stampi la tabbellina del 10 ben formattata
*/

int main()
{

    cout << "Tabbelline fino al 10\n";
    for (int r = 0; r <= 10; r++){
        for (int c = 0; c <= 10; c++){
            if(r == 0 && c != 0) cout << c;
            else if(r != 0 && c == 0) cout << r;
            else if (r != 0 && c != 0) cout << c * r;            
            cout << "\t";            
        }   
        cout << "\n";
    }





}



