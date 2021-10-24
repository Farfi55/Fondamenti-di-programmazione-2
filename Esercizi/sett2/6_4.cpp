
/*
	letta una sequenza di numeri terminata da -1
	di al più 100 elementi
	memorizzarla e compattare l'array
	cioè eliminare tutti i numeri duplicati
	e eliminare tutti i buchi che si generano spostando a sinistra gli elementi rimanenti
*/

/*

in:		1 3 5 1 5 7 8
		1 3 5 5 7 8
out:	1 3 5 7 8

*/

#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
void LeggiArray(int* v, int &dim);
void Compatta(int* v, int &dim);
void Stampa(int* v, int dim);


int main(){
	int v[MAX_SIZE];
	int dim = 0;


	LeggiArray(v, dim);

	Compatta(v, dim);

	Stampa(v, dim);
	
	return 0;
}



void LeggiArray(int* v, int &dim)
{
	int input;
	cin >> input;
	while (input != -1)
	{
		v[dim++] = input;
		cin >> input;
	}
}


void Compatta(int v[], int &dim){
	int original_dim = dim;

	for (int i = 0; i < original_dim-1; i++){
		if (v[i] == -1) continue;  
		for (int j = i+1; j < original_dim; j++){
			if (v[i] == v[j]){
				v[j] = -1;
				dim--;
			}
		}
	}

	cout << original_dim << " -> " << dim << endl;
	Stampa(v, original_dim);

	int offset = 0;
	for (int i = 0; i < original_dim; i++){
		if(v[i] == -1) offset++;
		else v[i-offset] = v[i];			
	}
}


void Stampa(int v[], int dim){
	for (int i = 0; i < dim; i++)
		cout << v[i] << " ";
	cout << endl;

}

