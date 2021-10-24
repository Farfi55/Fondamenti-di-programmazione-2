#include <iostream>
using namespace std;

/* 
    Sommare un numero indefinito di interi letti da input
*/

int main()
{
    int sum = 0, val;
    while (cin >> val)
    {
        sum += val;
        cout << sum << endl;
    }

    //quando i blocchi includono una sola istruzione si possono omettere le parentesi graffe
    return 0;
}
