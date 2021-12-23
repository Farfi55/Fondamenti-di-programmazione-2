#include "../../Implementazioni/Grafo/non_orientato/GrafoNonOrientato.h"
#include <climits>
using namespace std;

bool stato(const Grafo& g, int nodo);
int max_lat(const Grafo& g);



int main(int argc, const char** argv) {

	int nodo_max = -1;
	int lat_max = INT_MIN;

	int n;
	cin >> n;

	Grafo g(n);

	// leggi il grafo
	cout << "il nodo " << max_lat(g) << " e' il nodo con stato 1 e latenza piu' alta";

	return 0;
}


bool stato(const Grafo& g, int nodo) {
	float media = 0;
	int n_adiacenti = 0;
	for(int i = 0; i < g.n(); i++) {
		if(i != nodo && g(i, nodo)) {
			media += g.lat(i);
			n_adiacenti++;
		}

	}
	media /= n_adiacenti;

	return g.lat(nodo) < media;
}


int max_lat(const Grafo& g) {
	for(int i = 0; i < g.n(); ++i) {
		if(g.lat(i) > lat_max && stato(g, i)) {
			lat_max = g.lat(i);
			nodo_max = i;
		}
	}
	return i;
}
