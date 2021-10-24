/*
	Leggere un array di dim elementi 
	determinare il massimo e stampare 
	numeri contenuti nell'array e 
	il relativo scarto dal massimo
*/

// es in: 3 5 6 2
// 	 out: 3:3  5:1  6:0  2:4

#include <iostream>
using namespace std;

int max(int* arr, int size);

int main(){

	int size;
	cin >> size;

	int arr[size];
	for (int i = 0; i < size; i++)
		cin >> arr[i];
	

	int massimo = max(arr, size);

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", " << massimo - arr[i] << endl;
	}
	
	
	return 0;
}

int max(int* arr, int size){
	int max = arr[0];
	for (int i = 1; i < size; i++)
		if(arr[i] > max) max = arr[i];
	return max;
}
