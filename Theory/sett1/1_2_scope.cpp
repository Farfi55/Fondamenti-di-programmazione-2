/**
 * @file 0_INDEX.md
 * 
 */

#include <iostream>
using namespace std;

// global
int reused = 42;

int main(){
    int unique = 0;
    cout << reused << ", " << unique << endl; // 42, 0
    
    //local
    int reused = 0;
    cout << reused << ", " << unique << endl; // 0, 0

    //per accedere la variabile globale invece di quella locale
    cout << ::reused << ", " << unique << endl; // 0, 0

}
