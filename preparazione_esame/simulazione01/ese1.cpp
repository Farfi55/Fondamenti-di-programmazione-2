#include <iostream>

using namespace std;


int main() {
	int* data_di_nascita = new int[8]{ 2,3,0,4,1,9,9,8 }; // data presa a caso

	// 1.
	// D: cosa stampa la seguente istruzione?
	cout << *(data_di_nascita + 2) << *(data_di_nascita + 3) << endl;
	// R: stamperà le due cifre che compongono il mese nella data di nascita
	// nel nostro caso "04"


	// 2.
	// D: la seguente istruzione è corretta?
	cout << *(data_di_nascita[2]) << endl;
	// R: No, data_di_nascita[2] è un valore ma lo stiamo trattando come fosse un indirizzo
	// questa istruzione non è corretta 


	// 3.
	// D: Cosa viene stampato al termine nella seguente porzione di codice?
	int& a = data_di_nascita[0];
	int b = data_di_nascita[1];

	a = a + b;
	b++;
	cout << data_di_nascita[0] << " " << data_di_nascita[1] << endl;
	// R: la var. a è un riferimento al primo elemento di data_di_nascita, mentre b è una semplice copia
	// quando andiamo a cambiare il valore di a, questo cambiamento è riportato anche all'interno dell'array
	// mentre al cambiare di b l'array rimane invariato
	// quindi nel nostro caso
	// data_di_nascita[0] = a = 2 + 3 = 5 
	// e quindi verrà stampato "5 3"
}
