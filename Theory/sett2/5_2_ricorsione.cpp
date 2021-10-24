#include <iostream>
using namespace std;


int fact(int val){
	if (val <= 1) return 1;
	else return fact (val-1) * val;
}


int main(){
	int val;
	cin >> val;
	cout << fact(val) << endl;

	return 0;
}


#if 0
//CHIAMATA		RETURN 					VALORE
fact(5)			fact(4) * 5				120 ^
fact(4)			fact(3) * 4				24 	^
fact(3)			fact(2) * 3				6 	^
fact(2)			fact(1) * 2				2 	^
fact(1)			1						1 	^

#endif
