#include <vector>
#include <iostream>
#include <algorithm>
#include "../../Implementazioni/Grafo/non_orientato/GrafoNonOrientato.h"

using namespace std;

struct Soluzione {
    // istanza
    Grafo& g;
    int k;

    // soluzione 
    vector<int> rimossi;

    Soluzione(int _k, Grafo& _g) : k(_k), g(_g), rimossi() {}
};


bool solve(Soluzione& sol);

bool canAdd(int nodo, const Soluzione& sol);

bool isComplete(const Soluzione& sol) {
    return sol.g.n() - sol.rimossi.size() == sol.k;
}


void add(int nodo, Soluzione& sol) { sol.rimossi.push_back(nodo); }
void remove(Soluzione& sol) { sol.rimossi.pop_back(); }


int main(int argc, char const* argv[])
{
    unsigned n; cin >> n;
    Grafo g(n);


    Soluzione sol();


    return 0;
}

bool solve(Soluzione& sol) {
    int nodo = 0;
    while(nodo <= sol.g.n()) {
        if(canAdd(nodo, sol)) {
            add(nodo, sol);

            if(isComplete(sol))
                return true;
            else if(solve(sol))
                return true;
            else {
                remove(sol);
            }
        }
        nodo++;
    }
    return false;
}

bool canAdd(int nodo, const Soluzione& sol) {
    if(find(sol.rimossi.begin(), sol.rimossi.end(), nodo) != sol.rimossi.end())
        return false;

    if(sol.g.n() - sol.rimossi.size() - 1 < sol.k)
        return false;

    for(int i = 0; i < sol.g.n(); i++) {
        if(sol.g(nodo, i) &&
            find(sol.rimossi.begin(), sol.rimossi.end(), nodo) != sol.rimossi.end()) {
            return false;
        }
    }
    return true;
}



