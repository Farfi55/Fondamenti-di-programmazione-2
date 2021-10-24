/*

esercizio:
 https://www.mat.unical.it/informatica/ProgrammaAdOggetti?action=AttachFile&do=get&target=Esercitazione04-03-2016.pdf


 7  2  2  0  1  3   1  3
 6     1  0  0  2  -1  6
 4          -1  1   2 -1 
*/
#include <iostream>

using namespace std;


void Inizializza(int* &pol, int size); 
int* Inizializza(int size);
void Dealloca(int* &pol); 
void stampa(const int* pol, int size);
void impostaCoefficente (int* pol, int potenza, int coefficente);
int* somma(const int* pol1, int size1, const int* pol2, int size2);
void cambiaGrado(int* &pol, int &oldSize, int newSize);
int* copia(int* pol, int size);


int main(){
	int grado1; cin >> grado1;
	int* pol1 = Inizializza(grado1);

	for (int i = grado1-1; i >= 0; --i)
	{
		int coeff; cin >> coeff;
		impostaCoefficente(pol1, i, coeff);
	}

	cout << "\npol1:\n";
	stampa(pol1, grado1);
	

	int grado2; cin >> grado2;
	int* pol2 = Inizializza(grado2);

	for (int i = grado2-1; i >= 0; --i)
	{
		int coeff; cin >> coeff;
		impostaCoefficente(pol2, i, coeff);
	}

	cout << "\npol2:\n";
	stampa(pol2, grado2);

	int* sommaPol = somma(pol1, grado1, pol2, grado2);
	int gradoSomma = max(grado1, grado2);

	cout << "\nsomma di pol1 e pol2:\n";
	stampa(sommaPol, gradoSomma);


	int grado3; cin >> grado3;
	int* pol3 = Inizializza(grado3);

	for (int i = grado3-1; i >= 0; --i)
	{
		int coeff; cin >> coeff;
		impostaCoefficente(pol3, i, coeff);
	}

	cout << "\npol3:\n";
	stampa(pol3, grado3);
	cambiaGrado(sommaPol, gradoSomma, grado3);
	
	cout << "\nsomma di pol1 e pol2 con il grado di pol3:\n";
	stampa(sommaPol, gradoSomma);

	int* tmp = somma(sommaPol, gradoSomma, pol3, grado3);
	gradoSomma = max(gradoSomma, grado3);
	Dealloca(sommaPol);
	sommaPol = tmp;

	cout << "\nsomma di (somma di pol1 e pol2) e pol3:\n";
	stampa(sommaPol, gradoSomma);


	Dealloca(pol1);
	Dealloca(pol2);
	Dealloca(sommaPol);
}




void Inizializza(int* &pol, int size) { 
	delete [] pol;
	pol = new int[size]; 
}

int* Inizializza(int size) { 
	return new int[size]; 
}

void Dealloca(int* &pol){
	delete [] pol; 
	pol = nullptr;
}

void stampa(const int* pol, int size)  {
	for (int i = size - 1; i >= 0 ; --i) 
		if(pol[i] != 0){
			if(pol[i] > 0 && i < size-1) cout << "+";
			if(pol[i] != 1) cout << pol[i];
			if(i > 1) cout << "p^" << i << " ";
			else if(i == 1) cout << "p ";
		}
	cout << endl;
}

void impostaCoefficente (int* pol, int potenza, int coefficente) { pol[potenza] = coefficente; }
int* somma(const int* pol1, int size1, const int* pol2, int size2){
	
	int max_size = max(size1, size2);
	int min_size = min(size1, size2);

	int* somma = new int[max_size];

	for (int i = 0; i < min_size; i++)
		somma[i] = pol1[i] + pol2[i]; 

	if(size1 > min_size)
		for (int i = size2; i < size1; i++)
			somma[i] = pol1[i];
	if(size2 > min_size)
		for (int i = size1; i < size2; i++)
			somma[i] = pol2[i];

	return somma;
} 

void cambiaGrado(int* &pol, int &oldSize, int newSize) { 
	int* newPol = new int[newSize];

	for(int i = 0; i < oldSize && i < newSize; ++i)
		newPol[i] = pol[i];

	delete [] pol;

	pol = newPol;
	oldSize = newSize;
}

int* copia(int* pol, int size){
	int* copia = new int[size];
	for (int i = 0; i < size; ++i){
		copia[i] = pol[i];
	}

	return copia;
}


