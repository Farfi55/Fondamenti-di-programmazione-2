#include <vector>
#include <string>

using namespace std;

struct Triple {
	string x, y, z;
};


struct Solution {
	vector<string> A;
	vector<Triple> C;

	const int n;
	const int m;

	// where curr[0] represents the value of the first string of A
	vector<int> curr;


	Solution(vector<string>& A, vector<Triple>& C) :
		A(A), C(C), n(A.size()), m(C.size()), curr(n, -1) {}

}


bool canAdd(Solution& sol, int i, int val) {
	if(sol.curr[i] != -1)
		return false;
	for(int j = 0; j < sol.n; j++) {
		if(sol.curr[j] == val)
			return false;
	}


	sol.curr[i] = val;
	for(int j = 0; j < sol.m; j++) {
		int x = sol.curr[sol.C[j].x];
		int y = sol.curr[sol.C[j].y];
		int z = sol.curr[sol.C[j].z];

		if(x != -1 && y != -1 && z != -1) {
			if(!((x < y && y < z) || (z < y && y < x)))
				return false;
		}
	}
	return true;
}

bool solve(Solution& sol, int position) {
	for(int val = 0; val < sol.n; val++) {

	}
}



string esercizio2(vector<string> A, vector<Triple> C) {


}

