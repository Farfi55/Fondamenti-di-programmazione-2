#include <vector>
#include <string>

using namespace std;



int val(string x);


// basato su div-coins

bool esercizio2(vector<string>& S) {
	vector<bool> chosen(S.size(), false);

	int total = 0;
	for(int i = 0; i < S.size(); i++) {
		total += val(S[i]);
	}

	// non possiamo trovare 2 sottoinsiemi con valore uguale 
	// se la somma totale è dispari
	if(total % 2 == 1)
		return false;


	vector<bool> possible_sums(total + 1, false);
	possible_sums[0] = true;


	for(int i = 0; i < S.size(); i++) {
		int val = val(S[i]);

		for(int j = total; j >= 0; j--) {
			if(possible_sums[j]) {
				possible_sums[j + val] = true;

				if(possible_sums[total / 2])
					return true;
			}

		}
	}

	return false;
}
