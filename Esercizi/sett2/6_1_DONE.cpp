
/* 
	data una matrice determinare 
	se tutte le coppie di righe 
	hanno almeno un elemento in comune 
	(anche colonne diverse)
*/

//TODO asdasd


#include <iostream>
using namespace std;


const int max_cols = 15;
bool righe_con_elemento_comune(const int matrix[][max_cols], int rows, int cols);
bool contiene(int element, const int* arr, int size);


int main(){

	int rows, cols;
	cout << "inserisci numero righe e colonne: ";
	cin >> rows >> cols;
	if(cols > max_cols) 
	{
		cerr << "Inserito un numero di colonne maggiore al massimo!\n";
		return -1;
	}

	int matrix[rows][max_cols];
	
	for (int r = 0; r < rows; r++){
		cout << "riga "<< r <<" Inserisci " << cols << " elementi: ";
		for (int c = 0; c < cols; c++)
			cin >> matrix[r][c];
	}
	
	if(righe_con_elemento_comune(matrix, rows, cols))
		cout << "La matrice ha almeno un elemento comune a tutte le righe" << endl;
	else
		cout << "La matrice non ha nessun elemento comune a tutte le righe" << endl;
	return 0;
}

bool righe_con_elemento_comune(const int matrix[][max_cols], int rows, int cols){
	for (int cx = 0; cx < cols; cx++){
		bool contenuto = true;
		for (int r = 1; r < rows && contenuto; r++)
			contenuto = contiene(matrix[0][cx], matrix[r], cols);
		
		if (contenuto) return true;
	}
	return false;
}


bool contiene(int element, const int* arr, int size){
	for (int i = 0; i < size; i++)
		if (element == arr[i])
			return true;
	return false;
}


