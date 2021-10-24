/*
	ricevuto un array di char
	determinare se rappresenta una parola palindroma
*/

#include <iostream>
using namespace std;

bool Palindroma(const char* parola, int dim){
	bool palindroma = true;

	for (int i = 0; i < (int)(dim/2) && palindroma; i++){
		if (parola[i] != parola[dim-i-1]) palindroma = false;
	}

	return palindroma;
}


int main(){

	int dim;
	cin >> dim;

	char parola[dim];

	cin >> parola;

	cout << Palindroma(parola, dim);

	return 0;
}
