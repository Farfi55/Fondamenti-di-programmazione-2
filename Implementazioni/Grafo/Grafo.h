// implementazione prof

#ifndef GRAFO_H_
#define GRAFO_H_

#include <cassert>
#include <vector>

using boolVec = std::vector<bool>;
#include<iostream>
using namespace std;
// grafo orientato
// (i,j) != (j,i)
class Grafo {
protected:
    // numero di nodi, numero di archi
    unsigned vn = 0, vm = 0;

    // matrice di adiacenza
    std::vector<boolVec> archi;  // vector<vector<bool>> (i,j) == true => esiste un arco da i verso j

    // inizializza la matrice di adiacenza
    void init(unsigned n) {
        this->vn = n;
        this->vm = 0;

        this->archi = std::vector<boolVec>(n);
        for(unsigned i = 0; i < n; i++)
            this->archi[i] = boolVec(n, false);
    }

public:
    Grafo(unsigned n) {
        assert(n >= 1);
        this->init(n);
    }

    // inserisce o elimina l'arco (i,j) (a seconda del valore di b)
    void operator()(unsigned i, unsigned j, bool b) {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        bool esisteArco = this->archi[i][j];
        if((!esisteArco && b) || (esisteArco && !b)) {
            this->archi[i][j] = b;  // arco i->j
            //this->archi[j][i] = b; // arco j->i (rende il grafo non orientato)
            if(b)
                vm++;
            else
                vm--;
        }
    }

    // elimina tutti gli archi
    void svuota() {
        for(unsigned i = 0; i < this->n(); i++)
            for(unsigned j = 0; j < this->n(); j++) {
                archi[i][j] = false;
                //archi[j][i] = false;
            }
        vm = 0;
    }

    Grafo& operator=(const Grafo& g) {
        if(this == &g)
            return *this;
        this->init(g.n());
        for(unsigned i = 0; i < this->n(); i++)
            for(unsigned j = 0; j < this->n(); j++)
                if(g(i, j))
                    this->archi[i][j] = true;
                else
                    this->archi[i][j] = false;
        return *this;
    }


    unsigned n() const { return vn; }
    unsigned m() const { return vm; }
    // true se l'arco (i,j) esiste, altrimenti false
    bool operator()(unsigned i, unsigned j) const {
        assert(i >= 0 && i < this->n() && j >= 0 && j < this->n());
        return this->archi[i][j];
    }

    void stampa() {
        for(unsigned i = 0; i < this->n(); i++)
            for(unsigned j = 0; j < this->n(); j++)
                cout << "(" << i << " " << j << ") = " << archi[i][j] << " ";

    }
};

#endif
