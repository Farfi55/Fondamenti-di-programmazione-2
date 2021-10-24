#include <iostream>
using namespace std;

bool cerca(const int v[], const int dim, const int x);

const int dim = 10;

int main(){
	int v[dim], x;
	cout << "Inserisci " << dim << " elementi\n";
	for (int i = 0; i < dim; i++){
		cin >> a[i];
	}
	cout << "inserisci l'elemento da cercare: ";
	cin >> x;

	if(cerca(v, dim, x)) cout << "TROVATO\n";
	else cout << "NON TROVATO\n";

}


bool cerca(const int v[], const int dim, const int x){
	bool trovato = false;	 
	for (int i = 0; i < dim && !trovato; i++){
		if (v[i] == x) trovato = true;
	}
	return trovato;
}


#if 0 
// stessa cosa, ma usando solo return

bool cerca(const int v[], const int dim, const int x){	 
	for (int i = 0; i < dim; i++)
		if (v[i] == x) return true;
	return false;
}
#endif
