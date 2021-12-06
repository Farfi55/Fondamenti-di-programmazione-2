#include <iostream>
#include <queue>
#include <list>
#include "../../../Implementazioni/Grafo/Grafo.h"


using namespace std;

bool trovaCammino(const Grafo& g, int s, int t, vector<bool>& visitati, list<int>& cammino);

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



void ricostruisciCammino(int s, int t, const vector<int>& p, queue<int>& cammino) {
    if(s == t) cammino.push(s);
    else if(t == -1) return;
    else {
        ricostruisciCammino(s, p[t], p, cammino);
        cammino.push(t);
    }
}


// bool trovaCammino(const Grafo& g, int s, int t, vector<bool>& visitati, list<int>& cammino) {

// }

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

    vector<int> predecessori = bfs(4, g);
    queue<int> q;

    ricostruisciCammino(3, 4, predecessori, q);

    while(q.empty()) {
        cout << q.front() << endl;
        q.pop();
    }


    return 0;
}

