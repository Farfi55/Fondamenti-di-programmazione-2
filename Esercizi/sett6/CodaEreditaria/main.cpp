#include <iostream>

#include "CodaEreditaria.cpp"

using namespace std;
int main() {
    CodaEreditaria coda;

    cout << "(termima con Ctrl+Z)\ninserisci lettere:\n";

    char lettera;
    while (cin >> lettera) {
        coda.aggiungi(lettera);
        cout << coda << endl;
    }

    coda.rimuovi();
    coda.rimuovi();
    cout << coda;
}
