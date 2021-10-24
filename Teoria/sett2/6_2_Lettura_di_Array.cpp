//Lettura di un Array
#include <iostream>

using namespace std;

const int dim = 10;

int main(){
	int a[dim];

	// LETTURA
	cout << "Inserisci " << dim << " elementi\n";
	for (int i = 0; i < dim; i++){
		cin >> a[i];
	}

	// SCRITTURA
	cout << "l'array letto e':\n";
	for (int i = 0; i < dim; i++){
		cout << a[i] << endl;

	return 0;	
}
