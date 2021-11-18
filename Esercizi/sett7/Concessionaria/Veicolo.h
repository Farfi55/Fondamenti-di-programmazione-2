#ifndef VEICOLO_H
#define VEICOLO_H


#include <iostream>
#include <string>

using std::ostream;
using std::string;



class Veicolo {


    friend ostream& operator << (ostream& out, const Veicolo& v) {
        return v.print(out);
    }

public:
    Veicolo();
    string getTarga() const { return targa; }
    string getCasaProduttrice() const { return CasaProduttrice; }
    string getNomeVeicolo() const { return nomeVeicolo; }
    virtual float getPrezzo() const { return prezzo; }
    virtual ostream& print(ostream&) = 0;
};

#endif // !VEICOLO_H
