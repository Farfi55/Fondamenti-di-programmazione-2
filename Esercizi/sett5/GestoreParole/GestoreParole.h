#ifndef GESTORE_PAROLE_H
#define GESTORE_PAROLE_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class GestoreParole {
   private:
    vector<string> parole;

   public:
    GestoreParole(){};

    void leggi();
    bool ripetizioni() const;
    bool esisteParola(string parola) const;
    bool esisteParolaConIniziali(string iniziali) const;

    void sostituisciIniziali(string iniziali);

    friend ostream& operator<<(ostream& o, const GestoreParole& gp);
};
#endif
