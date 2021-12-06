/*
VISITE SU GRAFI:

- Mi serve un nodo di partenza
// - L'ordine non

- Profondità (DFS depth first search)
- Ampiezza (BFS Bread first search)

z


*/

#include <vector>
#include <queue>
#include <list>
#include <iostream>
using namespace std;



#include "../../../Implementazioni/Grafo/Grafo.h"

void dfs(int s, const Grafo& g, vector<bool>& visitati);
void bfs(int s, const Grafo& g, vector<bool>& visitati);




int main(int argc, char const* argv[])
{
    int n, u, v;
    cin >> n;
    Grafo g(n);

    while(cin.good()) {
        cin >> u;
        if(u == -1) break;
        cin >> v;

        g(u, v, true);
    }

    for(int i = 0; i < g.n(); i++) {
        cout << "archi di " << i << ":\n";
        for(int j = 0; j < g.n(); j++) {
            if(i != j && g(i, j))
                cout << "(" << i << ", " << j << ") ";
        }
        cout << endl;

    }



    return 0;
}




// TODO
// usando questa funzione, scrivere una funzione che calcoli la chiusura transitiva
// la chiusura transitiva è un grafo dove vengono esplicitati i collegamenti da un arco ad un altro
// che potevano essere raggiunti da un percorso

void dfs(int s, const Grafo& g, vector<bool>& visitati)
{
    // valuta s
    // g(s) ...
    visitati[s] = true;
    for(int j = 0; j < g.n(); j++)
        if(s != j && g(s, j) && !visitati[j])
            dfs(j, g, visitati);
}




// chiusura transitiva
Grafo chiusuraTransitiva(const Grafo& g)
{
    // implementazione in O(n^3)

    Grafo g_chiusura_transitiva(g.n());

    for(int i = 0; i < g.n(); i++) {
        vector<bool> visitati(g.n(), false);
        dfs(i, g, visitati);
        for(int j = 0; j < g.n(); j++) {
            if(i != j && visitati[j])
                g_chiusura_transitiva(i, j, true);
        }
    }

    return g_chiusura_transitiva;
}




// retituisce per ogni nodo il predecessore


vector<int> bfs(int s, const Grafo& g)
{
    vector<bool> visitati;
    vector<int> prec(g.n(), -1); // predecessori inizializzati a -1
    queue<int> q;

    // passo iniziale: prec[s] = s
    q.push(s);
    prec[s] = s;
    visitati[s] = true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        // elaboro il nodo u

        for(int v = 0; v < g.n(); v++)
            if(v != u && g(u, v) && !visitati[v]) {
                visitati[v] = true;
                prec[v] = u;
                q.push(v);
            }
    }

    return prec;

}
