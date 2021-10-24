
#include <iostream>
using namespace std;


const int N = 3;


void LeggiMatrice(int M[][N]);

int main(){

	int M[N][N];


	for (int r = 0; r < N; r++){
		for (int c = 0; c < N; c++){
			int elem = M[r][c];
			int size = 1;
			while (r + size <= N && c + size <= N)
			{
				for (int h = 0; h < size; h++)
					for (int w = 0; w < size; w++)
					{
						if(h == 0 && w == 0) continue;
					
						if(M[r+h][c+w] != elem) return size;

					}

			}
			

		}
		
	}

	LeggiMatrice(M);

}


void LeggiMatrice(int M[][N]){
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> M[i][j];
}

