#include <iostream>
using namespace std;

/* 
    determinare il massimo di una sequenza di lettere da input
*/

int main()
{
    //sintassi if

    if(false /*condizione*/){
        // blocco if 
    }
    else if (true /*condizione*/){
        // blocco else if
    }
    else {
        // blocco else
    }



    int currVal, maxVal;
    if (cin >> currVal){
        maxVal = currVal;

        while (cin >> currVal)
        {
            if(currVal > maxVal){
                maxVal = currVal;
            }
            cout << "Il valore massimo è: "<< maxVal << endl;
        }
        

    }




}