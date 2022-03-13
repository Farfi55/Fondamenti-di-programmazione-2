#pragma once
#include <string>
#include <vector>
#include <set>

#include "Persona.fwd.h"
#include "Grafo.fwd.h"

using namespace std;

class Persona {
    friend class Grafo;
private:
    string cf;
    string nome;
    string cognome;
    int eta;
    set<string> settori;
public:

    Persona(string _cf, string _nome, string _cognome, int _eta, set<string> _settori) :
        cf{ _cf }, nome{ _nome }, cognome{ _cognome }, eta{ _eta }, settori{ _settori }
    {}

    bool appartieneASettore(string settore) const {
        return settori.find(settore) ;
    }

    bool settoreInComune(const Persona& persona) const {
        for(string settore : settori) {
            if(persona.appartieneASettore(settore))
                return true;
        }
        return false;
    }

    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    string getCF() const { return cf; }
    int getEta() const { return eta; }



private:
    void aggiugngiSettore(string settore) {
        settori.insert(settore);
    }

    void rimuoviSettore(string settore) {
        settori.erase(settore);
    }
};
