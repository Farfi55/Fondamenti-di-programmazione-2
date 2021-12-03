#include <iostream>
#include <list>
#include <vector>
#include <climits>


using namespace std;

#include "grafoPesato.h"
list<int> calcolaCamminoMinimoGoloso(GrafoPesato g, int da, int a);

int main(int argc, char const* argv[])
{
    GrafoPesato g(4);
    g(0, 1, true, 7);
    g(0, 2, true, 5);
    g(1, 3, true, 4);
    g(2, 3, true, 10);

    list<int> cammino = calcolaCamminoMinimoGoloso(g, 0, 3);

    if(cammino.empty())
        cout << "Nessuna soluzione trovata" << endl;
    else {
        cout << "SOLUZIONE TROVATA: " << endl;

        int costoTotale = 0;
        for(auto it = cammino.begin(); it != cammino.end() - 1; it++) {
            cout << *it << " -> ";
            costoTotale += g.w(*it, *(next(it, 1)));
        }

    }
    return 0;
}



list<int> calcolaCamminoMinimoGoloso(GrafoPesato g, int da, int a) {
    vector<bool> visitati(g.n(), false);
    visitati[da] = true;


    list<int> cammino;
    cammino.push_back(da);

    if(da == a) return cammino;


    do {
        int prossimoNodo = sceltaGolosa(g, da, visitati);

        if(prossimoNodo == -1) return list<int>();

        visitati[prossimoNodo] = true;
        cammino.push_back(prossimoNodo);
        da = prossimoNodo;
    } while(da != a)

}

int sceltaGolosa(GrafoPesato g, int da, vector<int> visitati) {

    int costoPerSuccessivo = INT_MAX;
    int migliorNodoSuccessivo = -1;


    for(int i = 0; i < g.n(); i++)
        if(!visitati[i] && g(da, i) < costoPerSuccessivo) {
            costoPerSuccessivo = g.w(da, i);
            migliorNodoSuccessivo = i;

        }
    return migliorNodoSuccessivo;
}

da 0 a 3

0->1: 4
0->2 : 6

1->2 : 3
1->3 : 4

2->3 : 7

(0) : tra 4 e 6 sceglie 4 e va in(1)
(1) : tra 3 e 4 sceglie 3 e va in(2)
(1) : sceglie 7 e va in(3)

percorso in output :
0->1->2->3
costo totale : 4 + 3 + 7 = 14

vero percoso ottimo
0->1->3 :
    costo totale : 4 + 4 = 8




    da 0 a 3

    0->1: 4
    0->2 : 6

    1->2 : 3
    1->3 : 4

    2->0 : 7 // è cambiato questo

    (0) : tra 4 e 6 sceglie 4 e va in(1)
    (1) : tra 3 e 4 sceglie 3 e va in(2)
    (2) : (1) è già stato visitato, non trova soluzione
