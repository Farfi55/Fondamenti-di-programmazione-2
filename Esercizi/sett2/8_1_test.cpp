#include <iostream>
using namespace std;

const int n = 3;
const int K = 2;


int main(){

	bool yes = true;
	int i;
	for (i = 0; i < 5 && yes; i++)
	{
		if(i == 3) yes = false;	
	}

	cout << i;
	

}
