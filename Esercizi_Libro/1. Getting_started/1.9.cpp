#include <iostream>
using namespace std;

/* 
Exercise 1.9: Write a program that uses a while to sum the numbers from
50 to 100.
*/
int main()
{
    int i = 50, sum = 0;
    while (i <= 100)
        sum += i++;

    std::cout << "the sum is: " << sum << endl;
    return 0;
}
