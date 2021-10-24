#include <iostream>
using namespace std;

const int n = 5;
const int K = 3;


void leggiMatriceA(int A[][n]);
void leggiMatriceQ(int Q[][K]);
bool verificaEsisteSimile(int A[][n], int Q[][K]);
bool verificaSimili(int A[][n], int Q[][K], int i, int j);

int main(){

	int A[n][n];
	int Q[K][K];


	leggiMatriceA(A);
	leggiMatriceQ(Q);


	if(verificaEsisteSimile(A, Q))
		cout << "Esiste una sottomatrice simile";
	else
		cout << "Non esiste";


	return 0;
}


void leggiMatriceA(int A[][n]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cout << "Inserisci A[" << i << " " << j << "]: ";
			cin >> A[i][j];
		}
}

void leggiMatriceQ(int Q[][K]){
	for (int i = 0; i < K; i++)
		for (int j = 0; j < K; j++){
			cout << "Inserisci Q[" << i << " " << j << "]: ";
			cin >> Q[i][j];
		}
}


bool verificaEsisteSimile(int A[][n], int Q[][K]){
	bool esisteSimile = false;
	int i, j;
	for (i = 0; i <= n-K && !esisteSimile; i++)
		for (j = 0; j <= n-K && !esisteSimile; j++)
		{
			esisteSimile = verificaSimili(A, Q, i, j);
		}

	// decrementiamo i e j di 1 in quanto vengono incrementati anche dopo
	// aver trovato che le matrici sono simili
	i--;
	j--;

	if (esisteSimile){
		for (int s = 0; s < K; s++)
			for (int t = 0; t < K; t++)
				A[i + s][j + t] = Q[s][t];
	} 

	for (int s = 0; s < n; s++)
		for (int t = 0; t < n; t++)
			cout << A[s][t] << " ";
		cout << endl;

	return esisteSimile;
		
	
}


bool verificaSimili(int A[][n], int Q[][K], int i, int j){
	int sommaDiagonaleA = 0, sommaDiagonaleQ = 0;

	
	for (int t = 0; t < K; t++){
		sommaDiagonaleQ += Q[t][t];
		sommaDiagonaleA += A[i + t][j + t];
	}

	return (sommaDiagonaleA == sommaDiagonaleQ);
}
