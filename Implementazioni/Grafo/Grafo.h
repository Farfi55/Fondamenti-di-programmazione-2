#include <vector>
using std::vector;

// TODO implementare
// bonus: scrivere la versione con liste di adiacenza

typedef vector<bool> vectorB;
// grafo con matrice di adiacenza
class Grafo {
protected:

    vector<vectorB> archi;

    // vn: numero nodi
    // vm: numero archi
    int vn, vm;

public:
    Grafo(int n);
    void operator()(int i, int j, bool b);
    bool operator()(int i, int j) const;

    int n() const { return vn; }
    int m() const { return vm; }


};


vector<int> numAdiacenti(const Grafo& g) {
    vector<int> grado(g.n());

    for(int i = 0; i < g.n(); i++) {
        grado[i] = 0;
        for(int j = 0; j < g.n(); j++) {
            if(i != j && g(i, j)) // i diverso da j ed esiste un collegamento da i a j
                grado[i]++;
        }
    }
    return grado;
}

// ricevuto un grafo orientato, restituisca un grafo non orientato
Grafo toNonOrientato(const Grafo& g) {
    Grafo gnor(g.n());

    for(int i = 0; i < g.n(); i++) {
        for(int j = 0; j < g.n(); j++) {
            if(i != j && g(i, j)) { // i diverso da j ed esiste un collegamento da i a j
                gnor(i, j) = true;
                gnor(j, i) = true;
            }
        }
    }

    return gnor;
}
