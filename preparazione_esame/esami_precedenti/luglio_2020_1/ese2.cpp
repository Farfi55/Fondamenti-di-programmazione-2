/*
https://prototypes.mat.unical.it/asd/traccia_online_luglio2020_1.pdf

ESERCIZIO 2
Dato in input un insieme U di stringhe, una collezione S di multiinsiemi i cui elementi appartengono ad U, e
un intero k, scrivere una funzione chiamata esercizio2 che prenda in input U, S e k, e restituisca true se è 
possibile scegliere al massimo k insiemi della collezione S tale che la loro unione sia uguale a U, altrimenti
restituisca false.L'unione di due insiemi a e b è definita nel clas 
elementi di a e b presi una sola volta).Non è possibile assumere che gli elementi in U e in S siano ordinati.

Assunzioni:
	* U è rappresentato da un vector<strig> (ArrayList<String> se si usa Java),
	* S è rappresentato da un vector<vector<strin>> (ArrayList<ArrayList<String>> se si usa Java),
	* U non contiene mai la stessa stringa più volte; ogn 
		contenere la stessa stringa più volte.


Esempio: la funzione dovrà restituire true poiché ère 
al massimo k (ovvero 3) multiinsiemi in S tale che la loro unione sia uguale ad U.

Due soluzioni d’esempio sono:
	- I due insiemi {xq, e, f } e {a, b}, la cui unione è uguale ad U.
	- I tre insiemi {b, e, f}, {a, b} e {xq, f}, la cui unione è uguale ad U.

U = { a, b, xq, e, f }
S = { {xq, e, f },
 {b, e, f},
 {a, b},
 {xq, f},
 {a, xq, e } }
k = 3

*/

#include <vector>
#include <string>
#include <iostream>

using namespace std;

struct Soluzione
{
	vector<string> U;
	vector<vector<string>> S;
	int k;

	vector<int> curr;

	Soluzione(vector<string>& _U, vector<vector<string>>& _S, int _k) :
		U(_U), S(_S), k(_k), curr() {}
};


bool canAdd(Soluzione& sol, int i) {
	if(sol.curr.size() == 0) return true;
	if(sol.curr.size() == sol.k) return false;

	// evitiamo di aggiungere sottoinsimi già testati
	if(i <= sol.curr.back()) return false;
	else return true;
}


bool isComplete(Soluzione& sol) {
	for(int i = 0; i < sol.U.size(); i++) {
		int trovato = false;

		for(int j = 0; j < sol.curr.size() && !trovato; j++) {
			vector<string>& sub = sol.S[sol.curr[j]];

			for(int k = 0; k < sub.size() && !trovato; k++) {
				if(sol.U[k] == sub[k])
					trovato = true;
			}

		}
		if(!trovato)
			return false;
	}

	return true;
}

bool solve(Soluzione& sol) {

	for(int i = 0; i < sol.S.size(); i++) {
		if(canAdd(sol, i)) {
			sol.curr.push_back(i);

			if(isComplete(sol)) return true;
			else if(solve(sol)) return true;

			sol.curr.pop_back();
		}
	}
	return false;
}

bool esercizio2(vector<string>& U, vector<vector<string>>& S, int k) {
	Soluzione sol(U, S, k);
	return solve(sol);
}



int main(int argc, char const* argv[])
{
	vector<string> U = { "a", "b", "xq", "e", "f" };
	vector<vector<string>>S = { {"xq", "e", "f" },
								{ "b", "e", "f"},
								{ "a", "b"},
								{"xq", "f"},
								{ "a", "xq", "e" } };
	int k = 3;

	cout << esercizio2(U, S, k) << endl;

	return 0;
}
