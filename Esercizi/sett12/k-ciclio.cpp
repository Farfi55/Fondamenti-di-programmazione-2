#include "../../Implementazioni/Grafo/Grafo.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Soluzione {
    const Grafo& g;

    vector<int> ciclo;

    unsigned k;

    Soluzione(Grafo& _g, unsigned _k) : g(_g), k(_k + 1), ciclo() {};
};


bool solve(Soluzione& sol);
bool canAdd(int nodo, const Soluzione& sol);
bool isComplete(Soluzione& sol) { return (sol.ciclo.size() == sol.k); }


void add(int nodo, Soluzione& sol) { sol.ciclo.push_back(nodo); }
void remove(Soluzione& sol) { sol.ciclo.pop_back(); };



int main(int argc, char const* argv[])
{
    cout << "inserisci numero nodi\n> ";
    unsigned n;
    cin >> n;
    Grafo g(n);


    cout << "inserisci archi (i,j)\n-1 per terminare\n> ";
    unsigned from, to;
    while(true) {
        cin >> from;
        if(from == -1) break;
        cin >> to;
        g(from, to, true);
    }

    cout << "inserisci dimensione ciclo\n> ";
    int k; cin >> k;

    Soluzione sol(g, k);

    if(solve(sol)) {
        cout << "soluzione trovata\n";
        for(int i = 0; i < sol.k - 1; i++)
            cout << sol.ciclo[i] << " -> ";;
        cout << sol.ciclo.back() << endl;
    }
    else
        cout << "soluzione non trovata\n";

    return 0;
}

bool canAdd(int nodo, const Soluzione& sol) {
    if(sol.ciclo.empty())
        return true;

    if(sol.g(sol.ciclo.back(), nodo)) {
        if(sol.ciclo.size() == sol.k - 1)
            return sol.ciclo.front() == nodo;

        return (find(sol.ciclo.begin(), sol.ciclo.end(), nodo) == sol.ciclo.end());
    }
    else return false;
}

bool solve(Soluzione& sol) {
    for(int nodo = 0; nodo < sol.g.n(); nodo++) {
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
    }
    return false;
}




