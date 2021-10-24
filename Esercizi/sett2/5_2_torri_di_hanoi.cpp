//TORRI DI HANOI
/*

  |		|		|
  *		|		|
 ***	|		|
*****	|		|

+/


a	b	c

1
2
3


2		1
3		


3	2 	1


3	1
	2

	1	3
	2
	

1	2	3


1		2
		3


		1
		2
		3
*/

#include <iostream>
using namespace std;



void move(int disks, char from, char to, char aux){
	static int tot_moves = 0;

	if(disks == 1) {
		cout << ++tot_moves <<":\tMove disk 1 from rod " << from << " to rod " << to << endl;
		return;
	}
	else {

		//sposta n-1 dischi in un altro punto
		move(disks -1, from, aux, to);
		//sposta il disco più grande sulla bacchetta finale
		cout << ++tot_moves << ":\tMove disk " << disks << " from rod " << from << " to rod " << to << endl;
		//riporto n-1 dischi al punto di partenza
		move(disks-1, aux, to, from);
	
		return;
	}
}

int main(){
	int n_disks;
	cout << "Insert how many disks there are: ";
	cin >> n_disks; 
	move(n_disks, 'A', 'C', 'B');

	return 0;
}
