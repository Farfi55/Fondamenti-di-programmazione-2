/*
https://prototypes.mat.unical.it/asd/traccia_online_luglio2020_2.pdf

ESERCIZIO 2
Data una collezione di insiemi I, dove ogni insieme Ij contiene dei numeri interi, e un intero positivo q,
scrivere una funzione esercizio2 che restituisca true se è poss 
essi siano disgiunti tra loro (ovvero, ogni coppia di insiemi non ha elementi in comune); altrimenti,
restituire false.

Assunzioni:
	• I è rappresentato da un vector<vector<int>> (ArrayList<ArrayList<int>> se si usa Java),
	• q è sempre un numero intero positivo e non può essere minore di 2
*/

#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;


struct Soluzione {
	vector<vector<int>> I;
	int q;

	vector<int> subs;
	unordered_set<int> nums;

	Soluzione(vector<vector<int>>& I, int q) :
		I(I), q(q), subs(), nums() {}
};


bool canAdd(Soluzione& sol, int i) {
	if(sol.subs.size() == 0) return true;
	if(i <= sol.subs.back()) return false;

	for(int j = 0; j < sol.I[i].size(); j++) {
		if(nums.count(sol.I[i][j]))
			return false;
	}
	return true;
}

bool solve(Soluzione& sol) {

	for(int i = 0; i < sol.I.size(); i++) {
		if(canAdd(sol, i)) {
			vector<int>& arr = sol.I[i];
			for(int j = 0; j < arr.size(); j++) {
				sol.nums.insert(arr[j]);
			}

			if(sol.subs.size() >= sol.q) return true;
			if(solve(sol)) return true;

			for(int j = 0; j < arr.size(); j++) {
				sol.nums.erase(arr[j]);
			}

		}
	}

	return false;
}

bool esercizio2(vector < vector<int>& I, int q) {
	Soluzione sol(I, q);
	return solve(sol);
}

