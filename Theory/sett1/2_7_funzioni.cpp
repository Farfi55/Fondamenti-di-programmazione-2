#include <iostream>
using namespace std;

// funzioni

/*
    Una lista è formata da
    - nome
    - tipo di ritorno
    - lista di parametri  
    - un corpo
*/


int fact (int val){
    int ret = 1;
    while (val > 1){
        ret *= val--;
    }
    return ret;

}

int main()
{
    int j = fact(5);
    cout << "Il fattoriale di 5 è: " << j << endl;
    return 0;
}

