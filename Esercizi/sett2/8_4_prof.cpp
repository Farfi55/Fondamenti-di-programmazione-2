
#include <iostream>
using namespace std;


const int N = 3;


void LeggiMatrice(int M[][N]);

int main(){

	int M[N][N];
	LeggiMatrice(M);


	calcolaSottomatriceMassimaUguale(M);
}


void LeggiMatrice(int M[][N]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];
}


void calcolaSottomatriceMassimaUguale(int M[][N]){
	for (int dim = N; dim >= 1; dim--){
		for (int riga = 0; riga <= N-dim; riga++)
			for (int colonna = 0; colonna <= N-dim; colonna++)
				if (controllaSottoMatrice(M, riga, colonna, dim)){
					cout << "Dimensione massima di sottomatrice: " << dim << endl;
					cout << "Coordinate del primo punto: [" << riga << "," << colonna << "]\n";
					cout << "Valore " << M[riga][colonna] << endl;
					return;
				}
	}
}

bool controllaSottoMatrice(int M[][N], int riga, int colonna, int dim){
	int elem = M[riga][colonna];
	for (int y = 0; y < dim; y++)
		for (int x = 0; x < dim; x++)
			if (elem != M[riga + y][colonna + x]) return false;
	return true;
}
