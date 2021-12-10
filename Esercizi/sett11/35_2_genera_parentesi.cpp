// 10-12-2021 09:42
/*
Dato un intero n, generare tutte le possibili stringhe s,
contenenti n parententesi (, che siano ben parentesizzate

n = 2 -> "()()", "(())"
n = 3 -> "((()))", "(()())", "(())()", "()(())", ...

*/


#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Soluzione {
    // soluzione
    vector<string> benParentesizzate;
    string current;
    int current_aperte;
    int current_chiuse;

    // istanza
    int n;

    Soluzione(int n_) : n(n_), current("") {}
};

void solve(Soluzione& soluzione);
bool canAdd(bool is_closed, const Soluzione& soluzione);
void add(bool is_closed, Soluzione& soluzione);
string get(bool is_closed);
void remove(Soluzione& soluzione);
bool isComplete(const Soluzione& soluzione);


int main(int argc, char const* argv[])
{
    cout << "Inserisci numero di parentesi: ";
    int n; cin >> n;

    Soluzione s(n);
    solve(s);

    for(string& benParentesizzata : s.benParentesizzate) {
        cout << benParentesizzata << endl;
    }


    return 0;
}

void solve(Soluzione& soluzione) {
    // se abbiamo già inserito n 
    int x = soluzione.current_aperte == soluzione.n;
    while(x < 2) {
        if(canAdd(x, soluzione)) {
            add(x, soluzione);

            if(isComplete(soluzione))
                soluzione.benParentesizzate.push_back(soluzione.current);

            solve(soluzione);

            remove(soluzione);
        }
        x++;
    }

}

string get(bool is_closed) {
    return !(is_closed) ? "(" : ")";
}

bool canAdd(bool is_closed, const Soluzione& soluzione) {
    if(is_closed)
        return soluzione.current_aperte > soluzione.current_chiuse;
    else
        return soluzione.current_aperte < soluzione.n;
}

void add(bool is_closed, Soluzione& soluzione) {
    soluzione.current += get(is_closed);
    if(is_closed) soluzione.current_chiuse++;
    else soluzione.current_aperte++;
}

void remove(Soluzione& soluzione) {
    bool is_closed = soluzione.current.back() == '(';
    soluzione.current.pop_back();

    if(is_closed) soluzione.current_chiuse--;
    else soluzione.current_aperte--;
}


bool isComplete(const Soluzione& soluzione) {
    return soluzione.current_aperte == soluzione.n &&
        soluzione.current_chiuse == soluzione.n;
}



