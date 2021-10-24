//VARIABILI STATICHE
//sono variabili che esistono per tutta la durata del programma

#include <iostream>
using namespace std;

int count_calls(){
	static int ctr = 0;
	return ++ctr;
}


int main(){
	for(int i = 0; i != 0; i++){
		cout << count_calls() << endl;
	}
	return 0;
}


#if 0
//OVERLOADING DELLE FUNZIONI
void f(int n);
void f(int n, int m);
void f(float n);
void f(auto n); // può essere causa di errori, da usare con cautela

void f1(int n); // ERRORE, il compilatore non riesce a capire quale di questi si vuole usare
int f1(int n);

#endif

