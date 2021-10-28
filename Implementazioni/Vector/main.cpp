#include <iostream>
#include "Vector.h"

int main(){
	Vector<int> v;
	for(int i = 0; i < 10; ++i)
		v.pushBack(i);
	// qui so quanto sarà la dimensione necessaria, conveniva usare un reserve invece di fare più ridimensionamenti
	// v.reserve(10);
	
	cout << "svuoto l'array ";
	while(v.size() > 0) {
		cout << v.back() << " ";
		v.popBack();
	} 
	// stampa 9 8 7 ... 0
	Vector<char> v2;
	for (int i = 0; i < 10; i++){
		char c;
		cin >> c;
		v2.pushBack(c);
	}
}
