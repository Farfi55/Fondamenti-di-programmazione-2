#include <iostream>
using namespace std;

// array di 3 righe e 4 colonne
int m[3][4];

// array 3-dimensionale 
int arr[10][20][30];

int m2[3][4] = {
	{0,1,2,3},
	{4,5,6,7},
	{8,9,10,11}
};

const int rowSize = 3;
const int colSize = 4;

void print (const int m[][colSize], int rowSize, int colSize);

// accesso 
int main(){
	
	cout << m2[1][2] << endl;

	// NON UTILIZZABILE
	// cout << m2[1,2] << endl; 
	
	print(m2, rowSize, colSize);
}


void print (const int m[][colSize], int rowSize, int colSize){

	for (int i = 0; i < rowSize; i++)
		for (int j = 0; j < colSize; j++)
			cout << m[i][j] << '\t';

		cout << endl;

}


