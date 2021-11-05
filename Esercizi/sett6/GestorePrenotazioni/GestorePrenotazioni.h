#ifndef GESTORE_PRENOTAZIONI_H
#define GESTORE_PRENOTAZIONI_H

#include <list>
#include <vector>

#include "Prenotazione.h"

using namespace std;

class GestorePrenotazioni {
   public:
    GestorePrenotazioni();
    GestorePrenotazioni(const GestorePrenotazioni&);
    ~GestorePrenotazioni();

    bool aggiungiPrenotazione(int posti, string codice);
    bool rimuoviPrenotazione(int numero);
    void stampaPrenotazioni(string codice) const;
    void ordinaPrenotazioni();

    GestorePrenotazioni& operator=(const GestorePrenotazioni&);

   private:
    list<Prenotazione*> prenotazioni;
    vector<string> codici = {"a0001", "b0002", "c0003", "d0004", "e0005",
                             "f0006", "g0007", "h0008", "i0009", "z0010"};
    vector<int> postiTotali = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    bool esistePrenotazione(int numero);
};

#endif
