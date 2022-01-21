/*
https://prototypes.mat.unical.it/asd/traccia_online_luglio2020_1.pdf


ESERCIZIO 1
Dato un grafo diretto e pesato G(V,E,w), con V rappresentante l'insieme dei nodi, E l'insieme degli archi e
w(u,v) indicante il peso dell'arco (u,v), scrivere una funzione chiamata esercizio1 che prenda in input il grafo
e restituisca true se per ogni nodo u ∈ 𝑉, la somma dei pesi degli archi uscenti da u è sempre magg dei 
singoli pesi di tutti gli archi uscenti dai nodi adiacenti di u; altrimenti, restituisca false. La condizione è sempre
valida per un nodo senza archi uscenti. I nodi adiacenti di un nodo a sono tutti i nodi x tale che esiste l’o 
(a,x).

Il grafo è rappresentato da una classe GrafoPesato, i cui metodi di interfaccia necessari a svolgere l’esercizio
sono i seguenti: data g un'istanza della classe GrafoPesato:
	* g.n() restituisce il numero di nodi del grafo,
	* g.m() restituisce il numero di archi del grafo,
	* g(i,j) restituisce un numero intero positivo p rappresentante il peso dell'arco (i,j), se questo esist;
		se l’arco (i,j) non esiste, la funzione restituisce -1.
I nodi del grafo sono etichettati da 0 a n-1.
*/

#include <vector>
#include <climits>

using namespace std;

bool esercizio1(const Grafo& g) {
	vector<int> max_uscente(g.n(), INT_MIN);

	for(int i = 0; i < g.n(); i++) {
		for(int j = 0; j < g.n(); j++)
			if(i != j && g(i, j) != -1)
				max_uscente[i] = max(max_uscente[i], g(i, j))
	}

	for(int i = 0; i < g.n(); i++) {
		int sum = 0;
		int max_uscente_adiacent = INT_MIN;
		for(int j = 0; j < g.n(); j++) {
			if(i != j && g(i, j) != -1) {
				sum += g(i, j);
				max_uscente_adiacent = max(max_uscente_adiacent, max_uscente[j]);
			}
		}

		if(sum <= max_uscente_adiacent)
			return false;

	}

	return true;

}
