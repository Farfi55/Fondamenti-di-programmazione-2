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
using namespace std;



#include "Grafo.h"

void dfs(int s, const Grafo& g, vector<bool>& visitati);
void bfs(int s, const Grafo& g, vector<bool>& visitati);




int main(int argc, char const* argv[])
{

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
                prev[v] = u;
                q.push(v);
            }
    }

    return prec;

}



void visitaPerLivelli(const AlberoB<int>& a) {
    if(a.nullo())
        return;

    std::queue<AlberoBInt> q;
    q.push(a);

    while(!q.empty()) {
        AlberoBInt temp = q.front(); // q.front() restituisce l'oggetto in 
//testa alla coda SENZA RIMUOVERLO
        q.pop();			 // q.pop() rimuove l'oggetto in testa alla coda

// elaborare l'albero temp
        std::cout << temp.radice() << ' ';

        if(!temp.figlio(SIN).nullo())
            q.push(temp.figlio(SIN));
        if(!temp.figlio(DES).nullo())
            q.push(temp.figlio(DES));
    }
}
