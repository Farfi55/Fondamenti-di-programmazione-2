#include "GestorePrenotazioni.h"

#include <ctime>
#include <iostream>
using namespace std;

GestorePrenotazioni::GestorePrenotazioni() {
    srand(time(0));  // time(0) restituisce il timestamp attuale
}

GestorePrenotazioni::GestorePrenotazioni(const GestorePrenotazioni &g) {
    srand(time(0));  // time(0) restituisce il timestamp attuale

    for (auto it = g.prenotazioni.begin(); it != g.prenotazioni.end(); it++) {
        Prenotazione *p1 = new Prenotazione(
            (**it).getNumero(), (**it).getPosti(), (**it).getCodice());
        prenotazioni.push_back(p1);
    }

    postiTotali = g.postiTotali;
}

GestorePrenotazioni::~GestorePrenotazioni() {
    for (auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
        delete *it;
}

bool GestorePrenotazioni::esistePrenotazione(int numero) {
    for (list<Prenotazione *>::iterator it = prenotazioni.begin();
         it != prenotazioni.end(); it++)
        if ((**it).getNumero() == numero) return true;

    return false;
}

bool GestorePrenotazioni::aggiungiPrenotazione(int posti, string codice) {
    for (int i = 0; i < 10; ++i) {
        if (codici[i] == codice) {
            if (postiTotali[i] >= posti) {
                int numeroPrenotazione = rand() % 10000;
                while (esistePrenotazione(numeroPrenotazione))
                    numeroPrenotazione = rand() % 10000;

                Prenotazione *p =
                    new Prenotazione(numeroPrenotazione, posti, codice);
                prenotazioni.push_back(p);
                postiTotali[i] -= posti;
                return true;

            } else {
                return false;
            }
        }
    }
    return false;
}

bool GestorePrenotazioni::rimuoviPrenotazione(int numero) {
    for (auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
        if ((**it).getNumero() == numero) {
            string codice = (**it).getCodice();

            // "c0005" --> '5' --> 4
            int pos = codice[codice.length() - 1] - '1';
            if (pos == -1) pos == 9;  // "g0010" --> '0' --> 9

            postiTotali[pos] += (**it).getPosti();

            delete (*it);
            prenotazioni.erase(it);
            return true;
        }

    return false;
}

void GestorePrenotazioni::stampaPrenotazioni(string codice) const {
    for (auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
        if ((**it).getCodice() == codice) cout << **it << endl;
}

void GestorePrenotazioni::stampaPrenotazioni() const {
    for (auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
        cout << **it << endl;
}

// restituisce true se p1 precede p2
// false altrimenti
bool ordinamento(Prenotazione *p1, Prenotazione *p2) {
    int codP1 = p1->getCodice()[0];
    int codP2 = p2->getCodice()[0];

    if (codP1 >= 'a' && codP1 <= 'c') {
        if (codP2 >= 'a' && codP2 <= 'c')
            return codP1 <= codP2;
        else
            return true;
    } else if (codP2 >= 'a' && codP2 <= 'c') {
        return false;
    } else
        return p1->getNumero() < p2->getNumero();
    // if (p1->getCodice()[0] == 'a') return true;
    // if (p2->getCodice()[0] == 'a') return false;

    // if (p1->getCodice()[0] == 'b') return true;
    // if (p2->getCodice()[0] == 'b') return false;

    // if (p1->getCodice()[0] == 'c') return true;
    // if (p2->getCodice()[0] == 'c') return false;

    // return p1->getNumero() < p2->getNumero();
}
void GestorePrenotazioni::ordinaPrenotazioni() {
    prenotazioni.sort(ordinamento);
}

GestorePrenotazioni &GestorePrenotazioni::operator=(
    const GestorePrenotazioni &g) {
    if (this != &g) {
        // elimino tutte le prenotazioni
        for (auto it = prenotazioni.begin(); it != prenotazioni.end(); it++)
            delete *it;

        prenotazioni.clear();
        for (auto it = g.prenotazioni.begin(); it != g.prenotazioni.end();
             it++) {
            Prenotazione *p1 = new Prenotazione(
                (**it).getNumero(), (**it).getPosti(), (**it).getCodice());
            prenotazioni.push_back(p1);
        }

        postiTotali = g.postiTotali;
    }

    return *this;
}
