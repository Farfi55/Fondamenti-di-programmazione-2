// ESERCIZIO DELLA CRICCA (k-clique) CON METODO DI BACKTRACKING 
// 09-12-2021

#include <vector>
#include "Grafo.h"
using std::vector;

struct Tsoluzione {
    Grafo G;
    int k;
    vector<int> W;

    Tsoluzione(const Grafo& _G, int _k) : G(_G), k(_k) {};
}

void add(int x, Tsoluzione& sol) {
    sol.W.push_back(x);
}

void remove(int x, Tsoluzione& sol) {
    sol.W.pop_back();
}

bool isComplete(const Tsoluzione& sol) {
    return sol.W.size() == sol.k;
}

bool canAdd(int x, const Tsoluzione& sol) {
    if(find(x, sol.W.begin(), sol.W.end()) != sol.W.end()) return false;
    for(int i = 0; i < sol.W.size(); i++)
        if(!sol.G(sol.W[i], x)) return false;

    return true;

}

bool solve(Tsoluzione& sol) {
    x = 0;
    while(x < sol.G.n())
        if(canAdd(x, sol)) {
            add(x, sol); //aggiungi x in coda a sol 
            if(isComplete(sol)) return true;
            else if(solve(sol)) return true;
            remove(x, sol); x++; //backtrack 
        }
        else
            x++;
    return false;

}



// TODO come esercizio rimodellare il problema 
// usando una soluzione con un vector di bool
