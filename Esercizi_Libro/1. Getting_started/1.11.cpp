#include <iostream>
using namespace std;

/* 
Exercise 1.11: Write a program that prompts the user for two integers.
Print each number in the range specified by those two integers.
*/

int main()
{
    int num1, num2;
    cout << "Inserisci due numeri: " << endl;
    cin >> num1 >> num2;
    cout << endl;
    int i = num1;

    while (i < num2)
    {
        cout << i++ << endl;
    }

    return 0;
}
