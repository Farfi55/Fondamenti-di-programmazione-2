//LOGARITMO INTERO
//calcolo del logaritmo intero

#include <iostream>
using namespace std;

int log_int(int base, int x);


int main(){
	int base, x;
	cin >> base >> x; 
	cout << "Il logaritmo di " << x << " in base " << base << " e': " << log_int(base, x) << endl;

	return 0;
}

int log_int(int base, int x){
	int log = 0;
	int y = 1;
	while(y <= x){
		y *= base;
		log += 1;
	}
	return log-1;


	this is 
}
