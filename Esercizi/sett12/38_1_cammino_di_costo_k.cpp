#include <iostream>
#include <vector>
#include <algorithm>
#include "../../Implementazioni/Grafo/GrafoPesato.h"

using namespace std;

struct Soluzione {

	/* ISTANZA */
	GrafoPesato g;
	int pesoCammino;
	int da;
	int a;
	/***********/

	/* SOLUZIONE */
	vector<int> cammino;
	/***********/

	Soluzione(GrafoPesato& g_i, int peso, int nodo_da, int nodo_a) : g(g_i), pesoCammino(peso), da(nodo_da), a(nodo_a) {
		cammino.push_back(nodo_da);
	}
};

void add(int nodo, Soluzione& soluzione) {
	soluzione.cammino.push_back(nodo);
}

void remove(Soluzione& soluzione) {
	soluzione.cammino.pop_back();
}

bool canAdd(int nodo, const Soluzione& soluzione) {
	if(!soluzione.g(soluzione.cammino.back(), nodo)) return false; //non esiste l'arco che collega l'ultimo nodo della soluzione corrente al mio nuovo nodo

	//controllo che aggiungendo il nuovo nodo non supero il peso richiesto
	int peso_attuale = 0;
	for(int i = 0; i < soluzione.cammino.size() - 1; i++) {
		int arco_da = soluzione.cammino[i];
		int arco_a = soluzione.cammino[i + 1];
		peso_attuale += soluzione.g.w(arco_da, arco_a);
	}

	if(peso_attuale + soluzione.g.w(soluzione.cammino.back(), nodo) > soluzione.pesoCammino)
		return false;

	//controllo che non abbia gia' visitato il nodo
	if(find(soluzione.cammino.begin(), soluzione.cammino.end(), nodo) != soluzione.cammino.end())
		return false;

	return true;

}

bool isComplete(Soluzione& soluzione) {
	if(soluzione.cammino.back() != soluzione.a)
		return false;

	int peso_attuale = 0;
	for(int i = 0; i < soluzione.cammino.size() - 1; i++) {
		int arco_da = soluzione.cammino[i];
		int arco_a = soluzione.cammino[i + 1];
		peso_attuale += soluzione.g.w(arco_da, arco_a);
	}

	return peso_attuale == soluzione.pesoCammino;
}

bool solve(Soluzione& soluzione) {
	int nodo = 0;

	while(nodo < soluzione.g.n()) {
		if(canAdd(nodo, soluzione)) {
			add(nodo, soluzione);

			if(isComplete(soluzione))
				return true;

			if(solve(soluzione))
				return true;

			remove(soluzione);
			nodo++;
		}
		else
			nodo++;
	}

	return false;
}


int main() {
	GrafoPesato g(5);
	g(0, 1, true, 5);
	g(1, 4, true, 7);
	g(2, 3, true, 5);
	g(3, 1, true, 6);
	g(4, 3, true, 4); g(4, 2, true, 1);

	int da, a, peso;
	cout << "Inserisci nodo di partenza, di arrivo e costo: ";
	cin >> da;
	cin >> a;
	cin >> peso;

	Soluzione s(g, peso, da, a);
	if(solve(s)) {
		cout << "SOLUZIONE: " << endl;
		for(int i = 0; i < s.cammino.size() - 1; i++) {
			cout << s.cammino[i] << " -> " << s.cammino[i + 1] << endl;
		}
	}
	else
		cout << "Nessuna soluzione!";

}
