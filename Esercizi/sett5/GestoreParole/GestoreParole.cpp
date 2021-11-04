#include "GestoreParole.h"

#include <iostream>
#include <string>
using namespace std;

void GestoreParole::leggi() {
    string curr;

    cin >> curr;
    while (curr != "0") {
        parole.push_back(curr);
        cin >> curr;
    }
}

bool GestoreParole::ripetizioni() const {
    for (int i = 0; i < parole.size() - 1; ++i)
        for (int j = i; j < parole.size(); ++j)
            if (parole[i] == parole[j]) return true;

    return false;
}

bool GestoreParole::esisteParola(string parola) const {
    for (int i = 0; i < parole.size(); ++i)
        if (parole[i] == parola) return true;

    return false;
}

bool GestoreParole::esisteParolaConIniziali(string iniziali) const {
    for (int i = 0; i < parole.size(); i++) {
        if (parole[i].substr(0, iniziali.size()) == iniziali) return true;
    }
    return false;
}

void GestoreParole::sostituisciIniziali(string iniziali) {
    for (auto&& parola : parole) {
        if (parola.size() >= 5) parola.replace(0, 3, iniziali);
    }
}

ostream& operator<<(ostream& o, const GestoreParole& gp) {
    cout << gp.parole.at(0);
    for (int i = 1; i < gp.parole.size(); i++) {
        o << ", " << gp.parole[i];
    }
    return o;
}
