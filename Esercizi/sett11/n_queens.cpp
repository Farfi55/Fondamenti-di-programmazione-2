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


bool canAdd(int queen_col, Soluzione sol) {
    int queen_row = sol.queens.size();
    for(int i = 0; i < count; i++) {
        if(queen_col == queens[i] || // stessa colonna
            ((queen_col - queen_col[i]) == (queen_row - i)) || // nella diagonale principale
            ((queen_col - queen_col[i]) == -(queen_row - i))) // nella diagonale secondaria
            return false;
    }

    return true;

}


#include <vector>
#include <iostream>
using std::cout;
using std::vector;
using std::cin;
using std::endl;


struct Soluzione
{
    const unsigned n;
    const unsigned map_size;
    vector<int> queens;

    Soluzione(unsigned _n) : n(_n), map_size(_n), queens(map_size, -1) {};
    Soluzione(unsigned _n, unsigned _map_size) : n(_n), map_size(_map_size), queens(map_size, -1) {};
};




int main(int argc, char const* argv[])
{


    return 0;
}



bool solve(Soluzione sol) {
    for(int x = 0; x < sol.map_size; x++)

}
