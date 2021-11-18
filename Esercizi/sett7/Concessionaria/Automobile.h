#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H


#include "Veicolo.h"
class Automobile : public Veicolo {
public:
    Automobile(string t, float p, string c, string n) : Veicolo(t, p, c, n) {}

    float getPrezzo() const {
        float p = Veicolo::getPrezzo();
        if(p < 10000)
            p = p - (p / 20);
        else if(p < 20000)
            p = p - (p / 10);
        return p;
    }

    Automobile* clone() const {
        return new Automobile(*this);
    }
};


#endif
