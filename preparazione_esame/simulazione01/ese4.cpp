#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;


struct Solution {
	vector<string> S;
	vector<vector<string>> L;
	int q;

	unordered_set<string> P;
};

bool canAdd(Solution& sol, string& str) {
	if(sol.P.find(str) != sol.P.end())
		return false;

	for(int i = 0; i < sol.L.size(); i++) {
		bool all_present = true;
		for(int j = 0; j < sol.L[i].size() && all_present; j++) {
			if(str != sol.L[i][j] // ||
				&& sol.P.find(sol.L[i][j]) == sol.P.end())
				all_present = false;
		}
		if(all_present)
			return false;
	}

	return true;
}

bool solve(Solution& sol) {
	for(string& str : sol.S) {
		if(canAdd(sol, str)) {
			sol.P.insert(str);

			if(sol.P.size() == sol.q) return true;
			if(solve(sol)) return true;

			sol.P.erase(str);
		}
	}
}



bool ese4(vector<string>& S, vector<vector<string>>& L, int q) {
	Solution sol = { S, L, q, {} };
	return solve(sol);
}


int main(int argc, char const* argv[])
{
	vector<string> S{ "a", "b", "c", "d", "e", "f" };
	vector<vector<string>> L{ {"a", "b", "c"}, {"a", "d"}, {"d", "e"}, {"b", "f"} };
	int q = 3;
	cout << esercizio4(S, L, q);
	return 0;
}
