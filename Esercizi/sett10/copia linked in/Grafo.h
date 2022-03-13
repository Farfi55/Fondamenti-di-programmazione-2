#pragma once
#include <string>
#include <iostream>
#include <unordered_map>
#include <vector>


#include "Grafo.fwd.h"
#include "Persona.h"

using namespace std;

class Grafo
{
    typedef vector<bool> boolVec;

private:
    vector<Persona> persone;
    unordered_map <string, int> index_persone;
    vector<boolVec> collegamenti;

public:
    unsigned n_persone;


    void init(vector<Persona>& _persone) {
        this->n_persone = _persone.size();

        this->collegamenti = vector<boolVec>(n_persone);
        for(unsigned i = 0; i < n_persone; i++)
            this->collegamenti[i] = boolVec(n_persone, false);

        creaCollegamenti();
        popolaIndexPersone();
    }

public:
    Grafo(vector<Persona>& _persone) {
        this->init(_persone);
    }

    void aggiungiSettore(Persona& p, string settore);
    void rimuoviSettore(Persona& p, string settore);

    void aggiungiPersona(Persona& p);
    void rimuoviPersona(Persona& p);


    void mostraCollegamenti() {
        cout << '\t';
        for(int i = 0; i < n_persone; i++) {
            cout << persone[i].getCF() << '\t';
        }
        for(int i = 0; i < n_persone; i++) {

            cout << endl << persone[i].getCF() << '\t';
            for(int j = 0; j < n_persone; j++) {
                cout << collegamenti[i][j] << '\t';
            }

        }
        cout << endl;
    }

private:

    void popolaIndexPersone() {
        for(int i = 0; i < n_persone; i++) {
            index_persone.insert(persone[i].getCF(), i);
        }
    }

    void creaCollegamenti() {
        for(int i = 0; i < n_persone; i++)
            for(int j = 0; j < n_persone; j++)
                if(i != j)
                    if(persone[i].settoreInComune(persone[j])) {
                        collegamenti[i][j] = true;
                        collegamenti[j][i] = true;
                    }

    }
};
