#include "Concessionaria.h"

bool Concessionaria::aggiungi(Veicolo* v) {
    for(auto veicolo : veicoli)
        if(veicolo->getTarga() == v->getTarga())
            return false;

    veicoli.push_back(v);
    return true;
}

bool Concessionaria::rimuovi(string targa) {
    for(auto veicolo : veicoli)
        if(veicolo->getTarga() == targa) {
            veicoli.erase(it);
            return true;
        }
    return false;
}

void Concessionaria::stampaPrezzo(string targa) const {
    for(auto veicolo : veicoli) {
        if(veicolo->getTarga() == targa) {
            std::cout << "il prezzo e' pari a: " << Veicolo->getPrezzo() << std::endl;
            return;
        }
    }
    cout << "Veicolo non trovato\n";
}


void Concessionaria::stampa() const {
    for(auto veicolo : veicoli) {
        cout << "il prezzo e' pari a: " << Veicolo->getPrezzo() << endl;
    }
}

