#include <iostream>

using namespace std;


const int n = 3;

void LeggiMatrice(int M[][n]);
void VettoreSomiglianza(int A[][n], int B[][n], int* V){
int GradoSomiglianza(int A[][n], int B[][n], int col);
bool allineateGrado3(int A[][n], int B[][n], int* V);



int main(){
	int A[n][n];
	int B[n][n];
	int V[n];

	LeggiMatrice(A);
	LeggiMatrice(B);

	VettoreSomiglianza(A, B, V);

	if(allineateGrado3(A, B, V))

	return 0;
}



void LeggiMatrice(int M[][n]){
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> M[i][j];
}


void VettoreSomiglianza(int* A, int* B, int* V){
	for (int j = 0; j < n; j++)
		V[j] =  GradoSomiglianza(A, B, j);
}



int GradoSomiglianza(int* A, int* B, int col){
	int somiglianza = 0;
	
	for (int ia = 0; ia < n; ia++)
		for (int ib = 0; ib < n; ib++)
			if(A[ia][col] == B[ib][col])
				somiglianza ++;
	
	return somiglianza;
}

bool allineateGrado3(int A[][n], int B[][n], int* V){
	for (int j = 0; j < n; j++)
		if (V[j] >= n-3 )
			for(int s = 0; s < n; s++)
				for(int t = 0; t < n; t++)
					if(A[s][j] == B[t][j] && abs(s-t) > 1)
						return false;
	
	return true;
}
