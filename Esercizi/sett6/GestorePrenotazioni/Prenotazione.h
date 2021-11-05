#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include <iostream>
#include <string>

using namespace std;

class Prenotazione {
    fried ostream& operator<<(ostream& o, const Prenotazione& p) {
        o << "[pre. " << p.get
    }

   private:
    int numero;
    int posti;
    string codice;

   public:
    Prenotazione(int n, int p, string c) : numero{n}, posti{p}, codice{c} {}
    int getNumero() const { return numero; }
    int getPosti() const { return posti; }
    string getCodice() const { return codice; }
}

#endif
