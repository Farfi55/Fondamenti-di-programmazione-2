#include <set>
#include <iostream>

#include "Grafo.h"
#include "Persona.h"
using namespace std;

int main()
{
    vector<Persona> persone = {
    Persona("frfl", "a", "f", 20, { "informatica", "ingegneria" }),
    Persona("rbpc", "r", "p", 23, { "economia", "ingegneria" }),
    Persona("lucc", "l", "k", 21, { "economia" }),
    Persona("popd", "p", "a", 21, { "ignegneria" }),
    Persona("sove", "s", "v", 24, { "informatica", "economia" }),
    };

    Grafo g(persone);

    g.mostraCollegamenti();
    return 0;
}
