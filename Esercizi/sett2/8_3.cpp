/*
	PUNTO DI SELLA
	Leggere da tastiera una matrice M di interi di dimensione N x N 
	(con N costante definita) e determinare se la matrice M ha un punto di sella
	Un punto di sella è un elemento della matriche che è contemporaneamente il minimo
	sulla riga ed il massimo sulla colonna
*/


#include <iostream>
using namespace std;


const int N = 3;


void LeggiMatrice(int M[][N]);
bool esistePuntoSella(int M[][N]);
bool isMin(int elem, int M[][N], int riga);
bool isMax(int elem, int M[][N], int col);
bool isPuntoSella(int M[][N], int riga, int col);
int trovaMin (int M[][N], int riga);
int trovaMax (int M[][N], int col);
	
int main(){

	int M[N][N];

	LeggiMatrice(M);

	if(esistePuntoSella(M))
		cout << "Punto di sella trovato!" << endl;
	else
		cout << "Nessun punto di sella trovato!" << endl;


	return 0;
}


void LeggiMatrice(int M[][N]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];
}


bool esistePuntoSella(int M[][N]){
	for (int r = 0; r < N; r++)
		int min = trovaMin(M,r);
		for (int c = 0; c < N; c++)
			int elem = M[r][c];
			int max = trovaMax(M,c);
			if(elem <= min && elem >= max)
				return true;

	return false;
}



bool isPuntoSella(int M[][N], int riga, int col){
	int elem = M[riga][col];
	return (isMin(elem, M, riga) && isMax(elem, M, col));	
}

bool isMin(int elem, int M[][N], int riga)
{
	for (int c = 0; c < N; c++)
		if(elem > M[riga][c])
			return false;
	return true;

}
bool isMax(int elem, int M[][N], int col){
	for (int r = 0; r < N; r++)
		if(elem < M[r][col])
			return false;
	return true;

}

int trovaMin (int M[][N], int riga){
	int min = M[riga][0];
	for (int c = 1; c < N; c++)
		if(M[riga][c] < min)
			min = M[riga][c];
	return min;			
}

int trovaMax (int M[][N], int col){
	int max = M[0][col];
	for (int r = 1; r < N; r++)
		if(M[r][col] > max)
			max = M[r][col];
	return max;	
}
