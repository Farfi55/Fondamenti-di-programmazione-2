//leggere un numero e determinare se è primo
// op MOD:   ( n%k ) -> resto

#include <iostream>
#include <cmath>
using namespace std;



bool e_primo(int num){
    bool e_primo = true;
    int i_limit = (int)sqrt(num);

    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num%2 == 0 || num%3 == 0) return false;
    for (int i = 5; i <= i_limit; i += 6)
        if (num % (i) == 0 || num % (i + 2) == 0)
            return false;
            

    return true;
}

int main()
{
    int num;
    cout << "Inserire numero: ";
    cin >> num;

    if (e_primo(num))
        cout << num << " è un numero Primo" << endl;
    else
        cout << num << " non è un numero Primo" << endl;
}
