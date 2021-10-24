// una funzione che data una matrice determini se esistono 2 righe 
// esattamente identiche

bool verifica ( const int m[][colSize], int rowSize, int colSize);

int main(){


	return 0;
}


bool verifica ( const int m[][colSize], int rowSize, int colSize){
	bool trovate = false;

	for (int r1 = 0; r1 < rowSize - 1 && !trovate; r1++){
		for (int r2 = r1 + 1; r2 < rowSize && !trovate; r2++){
			
			bool uguali = true;

			for (int c = 0; c < colSize && uguali; c++){
				if (m[r1][c] != m[r2][c])
					uguali = false;
			}
			if(uguali) trovate = true;
		}
	}

	return trovate;
}
