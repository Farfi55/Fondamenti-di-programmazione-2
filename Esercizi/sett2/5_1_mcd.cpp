#include <iostream>
using namespace std;

//MCD (masimo comune divisore) Ricorsivo
// mcd (x,y) = x se y = 0
// mcd (x,y) = mcd(y,r) se y > 0
// x = q * y + r  con 0 <= r < y


int mcd(int x, int y){
	int resto = x % y;
	if (resto == 0) return y;
	else return mcd(y, resto);
}

int main(){
	int x, y;
	cout << "inserisci due valori x e y: ";
	cin >> x >> y;

	cout << "Il loro minimo comune divisore e': " << mcd(x, y) << endl;
	
	return 0;
}




