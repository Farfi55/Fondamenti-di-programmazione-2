#ifndef PRENOTAZIONE_H
#define PRENOTAZIONE_H

#include <iostream>
#include <string>

using namespace std;

class Prenotazione {
    friend ostream& operator<<(ostream& o, const Prenotazione& p) {
        o << "[pre. " << p.getNumero() << "] per " << p.getCodice() << ":"
          << p.getPosti() << " posti";
        return o;
    }

   private:
    int numero;
    int posti;
    string codice;

   public:
    Prenotazione(int numero, int posti, string codice)
        : numero{numero}, posti{posti}, codice{codice} {}
    int getNumero() const { return numero; }
    int getPosti() const { return posti; }
    string getCodice() const { return codice; }
};

#endif
