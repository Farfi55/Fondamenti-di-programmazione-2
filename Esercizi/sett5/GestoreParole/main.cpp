#include <iostream>

#include "GestoreParole.cpp"

using namespace std;

int main() {
    GestoreParole gp;

    gp.leggi();

    cout << gp << endl;

    string parola;
    cin >> parola;
    if (gp.esisteParola(parola))
        cout << "e' presente la parola " << parola << endl;

    if (!gp.ripetizioni()) cout << "non ";
    cout << "sono presenti ripetizioni tra le parole\n";

    string iniziali;
    cin >> iniziali;

    if (!gp.esisteParolaConIniziali(iniziali)) {
        cout << "non ";
    }
    cout << "trovata una parola che inizia con: " << iniziali << endl;

    gp.sostituisciIniziali(iniziali);

    cout << gp << endl;
}
