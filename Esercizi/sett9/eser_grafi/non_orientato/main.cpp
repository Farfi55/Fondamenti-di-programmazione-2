#include <iostream>
#include "GrafoNonOrientato.h"
#include "..\..\..\Implementazioni\Grafo\non_orientato\GrafoNonOrientato.h"
using namespace std;

void stampaGrafo(const GrafoNonOrientato& g);
int getNodoGradoMassimo(const GrafoNonOrientato& g);
bool almenoUnNodoAdiacenteATutti(const GrafoNonOrientato& g);
int gradoNodo(const GrafoNonOrientato& g, int nodo);

int main(int argc, char const* argv[])
{
    GrafoNonOrientato g(5);

    g(0, 1, true);
    g(1, 2, true); g(1, 3, true); g(1, 4, true);
    g(3, 4, true);

    stampaGrafo(g);

    cout << "Il nodo con grado massimo e': " << getNodoGradoMassimo(g) << endl;

    return 0;
}


void stampaGrafo(const GrafoNonOrientato& g) {
    cout << "Numero nodi: " << g.n() << endl;
    cout << "Numero archi: " << g.m() << endl;

    for(int i = 0; i < g.n() - 1; i++)
        for(int j = i + 1; j < g.n(); j++)
            if(g(i, j))
                cout << "Arco: " << i << "<->" << j << endl;
}

int getNodoGradoMassimo(const GrafoNonOrientato& g) {
    int nodo_max = -1, grado_max = -1;

    for(int i = 0; i < g.n(); i++) {
        int grado = gradoNodo(g, i);

        if(grado > grado_max) {
            grado_max = grado;
            nodo_max = i;
        }
    }
    return nodo_max;
}


bool almenoUnNodoAdiacenteATutti(const GrafoNonOrientato& g) {
    for(int i = 0; i < g.n(); i++) {
        int grado = gradoNodo(g, i);
        if(g(i, i)) grado--;
        if(grado == g.n() - 1)
            return true;
    }
    return false;
}

int gradoNodo(const GrafoNonOrientato& g, int nodo) {
    int grado = 0;
    for(int j = 0; j < g.n(); j++)
        if(g(nodo, j))
            grado++;
    return grado;
}
