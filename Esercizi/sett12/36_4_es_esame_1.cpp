#include <iostream>
using namespace std;


void f(int* matricola) {
    for(int i = 0; i < 3; i++) {
        int* a = new int(*(matricola + i));
        *(matricola + i) = *(matricola + 5 - i);
        matricola[5 - i] = *a;
    }

}


int main(int argc, char const* argv[])
{
    int* matricola = new int[6]{ 1, 7, 6, 1, 8, 3 };
    cout << *matricola << endl; // corretto, stampa 1
    cout << *(&matricola[2]) << endl; // corretto, stampa 6

    // sbagliata, dereferenzia il valore come fosse un indirizzo
    cout << *(matricola[2]) << endl;

    cout << *(matricola + 4) << endl; // corretto, stampa il 5° elemento, 8

    f(matricola);

    for(int i = 0; i < 6; i++) {
        cout << matricola[i] + i << " ";
    }

    matricola++;
    int* p = &matricola[3];
    for(int i = 0; i <= 2; i++) {
        cout << *(p - i) << endl;
    }

    // quali delle seguenti istruzioni va utilizzata per deallocare correttamente un array
    delete matricola[];
    delete matricola[6];
    delete[] matricola; // corretto
    delete[6] matricola;
    delete* matricola;


    return 0;
}

