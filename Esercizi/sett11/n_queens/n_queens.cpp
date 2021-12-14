/*
    usando una matrice è intuitivo ma rende il problema difficile da risolvere

    rappresentandolo come sottoproblemi i
    dove i è l'i-esima regina
stabilisce dove inserire la i-esima regina
s[i] la pos (colonna) della regina nella riga i
s[i] in (0, n-1)
min_val = 0
max_val = n - 1

next: x++
add: push_back()
remove: pop_back()

isComplete: s_size() == n
*/



/*
     0  1  2  3
0   00 01 02 03
1   10 11 12 13
2   20 21 22 23
3   30 31 32 33
*/

#include <vector>
#include <iostream>
using namespace std;

struct QSoluzione
{
    const unsigned n;
    int current_row;
    vector<int> queens;

    QSoluzione(unsigned _n) : n(_n), current_row(0), queens(n, -1) {  };
};

bool solve(QSoluzione& sol);
bool canAdd(int queen_col, QSoluzione& sol);
bool isComplete(QSoluzione& sol) { return sol.current_row == sol.n; }


void add(int queen_col, QSoluzione& sol) { sol.queens[sol.current_row++] = queen_col; }
void remove(QSoluzione& sol) { sol.current_row--; }


int main(int argc, char const* argv[])
{
    int n; cin >> n;

    QSoluzione sol(n);

    if(solve(sol)) cout << "risolto\n";
    else cout << "non risolto\n";

    for(auto&& q : sol.queens) {
        cout << q << endl;
    }


    for(int i = 0; i < n; i++) {
        int col = sol.queens[i];
        for(int j = 0; j < col; j++) cout << "| . ";
        cout << "| Q ";
        for(int j = col + 1; j < n; j++) cout << "| . ";
        cout << "|\n";
        for(int j = 0; j < n; j++) cout << "____";
        cout << "_" << endl << endl;
    }

    return 0;
}

bool solve(QSoluzione& sol) {
    for(int x = 0; x <= sol.n; x++) {
        if(canAdd(x, sol)) {
            add(x, sol);

            if(isComplete(sol))
                return true;
            else if(solve(sol))
                return true;
            else remove(sol);
        }
    }
    return false;
}



bool canAdd(int queen_col, QSoluzione& sol) {
    for(int i = 0; i < sol.current_row; i++) {
        if(queen_col == sol.queens[i] || // stessa colonna
            ((queen_col - sol.queens[i]) == (sol.current_row - i)) || // nella diagonale principale
            ((queen_col - sol.queens[i]) == -(sol.current_row - i))) // nella diagonale secondaria
            return false;
    }
    return true;
}

