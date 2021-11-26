#pragma once

#include "..\Grafo.h"

class GrafoNonOrientato : protected Grafo
{
public:
    GrafoNonOrientato(unsigned n) : Grafo(n) {}


    void operator()(unsigned i, unsigned j, bool b) {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        bool esisteArco = this->archi[i][j];
        if((!esisteArco && b) || (esisteArco && !b)) {
            this->archi[i][j] = b;  // arco i->j
            this->archi[j][i] = b; // arco j->i (rende il grafo non orientato)
            if(b)
                vm++;
            else
                vm--;
        }
    }


    bool operator()(unsigned i, unsigned j) const {
        // va bene perché ogni volta che inseriamo un arco per j, i 
        // lo facciamo anche per i, j
        return Grafo::operator()(i, j);
    }
    using Grafo::n;
    using Grafo::m;
    using Grafo::svuota;
    //using Grafo::operator()(unsigned i, unsigned j);


};
