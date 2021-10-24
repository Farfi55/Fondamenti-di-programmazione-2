// ALLOCARE ARRAY BUILT-IN DINAMICAMENTE
#include <iostream>
using namespace std;


#if 0 
const int capacity1 = 35;
int *elenco1 = new int[capacity];

// anche così
int cap2;
cin >> cap2;
int *elenco2 = new int [cap2];

delete[] elenco2;
delete[] elenco;
#endif


// vogliamo leggere una sequenza di numeri da tastiera, 
// senza sapere quanti siano e caricarli in un array di interi

void resize(int* &v, int &capacity, int increment);
void stampa(int *v, const int size);

const int dim_base = 10;

int main(){

	int * elenco = new int [dim_base];
	int elem, size = 0, capacity = dim_base;

	while (cin >> elem)
	{
		if (size < capacity) 	// c'è ancora spazio?
			elenco[size++] = elem;
		else{ 					// creo nuovo spazio: ingrandisci l'array
			resize(elenco, capacity, dim_base); 
			elenco[size++] = elem;
		}
		
	}

	stampa(elenco, size);
	return 0;
}


//  int * &v:  passo il puntatore v per riferimento così da poterlo modificare
void resize(int* &v, int &capacity, int increment){
	int* temp = new int[capacity + increment];

	for (int i = 0; i < capacity; i++)
		temp[i] = v[i];

	delete [] v; //cancello il vecchio array

	v = temp;
	cout << capacity;
	capacity += increment; 
	cout << " -> " << capacity << endl;
}

void stampa(int *v, const int size){
	for (int i = 0; i <	size; i++) cout << v[i] << " ";
	cout << endl;
}
