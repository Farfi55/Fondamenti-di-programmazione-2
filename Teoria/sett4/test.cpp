#include <iostream>
using namespace std;


class Dummy{
public:
	static int n;
	Dummy(){ n++; }
};
Dummy::n = 0;

int main(){

	Dummy o;
	Dummy a[5];

	cout << o.n << endl; // stampa 6 
	
	Dummy * c = new Dummy;
	
	cout << Dummy::n << endl; // stampa 7
	delete c;

	cout << Dummy::n << endl; // stampa 7

}
