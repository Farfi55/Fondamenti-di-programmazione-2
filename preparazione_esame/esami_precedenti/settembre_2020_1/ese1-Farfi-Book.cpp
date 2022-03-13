#include <vector>
#include <queue>

using namespace std;


struct Grafo
{
	int n();
	int m();
	int operator() (int i, int j);
};


void dfs(Grafo& g, vector<int>& nodi_raggiungibili, int start_node) {
	queue<int> nodes;
	vector<bool> visited(g.n, false);
	visited[start_node] = true;
	nodes.push(start_node);

	while(!nodes.empty()) {
		int i = nodes.front(); nodes.pop();

		for(int j = 0; j < g.n(); j++) {
			if(!visited[j] && g(i, j)) {
				visited[j] = true;
				nodes.push(j);
				nodi_raggiungibili[j]++;
			}
		}
	}
}

int esercizio1(Grafo& g) {
	vector<int> nodi_raggiungibili(g.n(), 0);
	for(int i = 0; i < g.n(); i++) {
		dfs(g, nodi_raggiungibili, i);
	}

	int nodo_piu_isolato = 0;

	for(int i = 0; i < g.n(); i++) {
		if(nodi_raggiungibili[i] < nodi_raggiungibili[nodo_piu_isolato])
			nodo_piu_isolato = i;
	}


	return g.n() - nodi_raggiungibili[nodo_piu_isolato];
}
