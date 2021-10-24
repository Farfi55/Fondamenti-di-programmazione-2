#include <iostream>
#include "4 punto.h"
using namespace std;

int main(){
    
    // sintassi while
    while (true /*condizione*/)
    {
        //blocco while
        break;
    }


    // somma dei numeri da 1 a 10

    int sum = 0;
    int val = 1;

    while (val <= 10)
    {
        sum += val;
        ++val;    
    }
    cout << sum << endl;
    

    
    //sintassi do-while
    sum = 0;
    val = 1;
    do {
        // blocco do while
        sum += val;
        ++val; 

    } while (val <= 10 /*condizione*/ )

    cout << sum << endl;



    //sintassi for
    sum = 0;

    //   init(1)    check(2)  update(4)
    for (val = 1;  val <= 10; val++)
    {
        // blocco (3)
        sum += val; 
    }
    cout << sum << endl;




    return 0;
}

