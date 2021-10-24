// SEQUENZA DI FIBONACCI
// 1 1 2 3 5 8 13 21 
// fib(1) = 1
// fib(2) = 1
// . . . 
// fib(n) = fib(n-1) + fib(n-2)
#include <iostream>

using namespace std;


int fib(int n){
	int f, f1 = 0, f2 = 1;
	if( n==0 || n == 1) return n;
	else
		for (int i = 0; i < n; i++)
		{
			f = f1 + f2;
			f2 = f1;
			f1 = f;
		}
	return f;
}

int fib_rec(int n){
	if( n == 0 || n == 1) return n;
	else return fib_rec(n-1) + fib_rec(n-2); 
}


int main(){
	int n;
	cin >> n;
	cout << fib(n) << endl;
	cout << fib_rec(n) << endl;

	return 0;
}
