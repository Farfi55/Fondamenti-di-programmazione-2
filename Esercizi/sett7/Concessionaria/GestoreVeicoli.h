#ifndef GESTORE_VEICOLI_H
#define GESTORE_VEICOLI_H

#include <list>
#include "Veicolo.h"
#include "Automobile.h"
#include "Moto.h"

using namespace std;
// using std::list;

class GestoreVeicoli {
public:
    void aggiungiAutomobile(string targa, float prezzo, string c, string n) {
        Automobile* a = new Automobile(targa, prezzo, c, n);
        aggiungiVeicolo(m);
    }

    void aggiungiMoto(string t, float p, string c, string n) {
        Moto* m = new Moto(t, o, c, n);
        aggiungiVeicolo(m);
    }

    Veicolo* getVeicolo(string targa) {
        for(auto veicolo : veicoli) {
            if(veicolo->getTarga() == targa)
                return veicolo;
        }
        return nullptr;
    }

    ~GestoreVeicoli() {
        // pulire la lista
        clear();
    }

    GestoreVeicoli operator= (const GestoreVeicoli& v) {
        if(this != &v) {
            // pulire la lista
            clear();
            // copiare la lista di veicoli di v
            for(auto veicolo : v.veicoli) {
                veicoli.push_back(veicolo->clone());
            }
        }

        return *this;
    }


    GestoreVeicoli(const GestoreVeicoli& v) {
        // copiare la lista di veicoli di v

    }

private:
    list<Veicolo*> veicoli;

    void aggiungiVeicolo(Veicolo* v) {
        for(auto veicolo : veicoli) {
            if(veicolo->getTarga() == v->getTarga())
                return;

            veicoli.push_back(v);
        }
    }

    void clear() {
        while(!veicoli.empty()) {
            delete veicoli.back();
            veicoli.pop_back();
        }
    }

}

#endif
