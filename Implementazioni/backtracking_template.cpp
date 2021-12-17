#include <vector>
#include <iostream>


using namespace std;

struct Soluzione {
    // data
    int n;


    Soluzione(int _n) : n(_n) {}
};


bool solve(Soluzione& sol);
bool canAdd(int x, const Soluzione& sol);
bool isComplete(const Soluzione& sol);


void add(int x, Soluzione& sol);
void remove(Soluzione& sol);


int main(int argc, char const* argv[])
{
    Soluzione sol();


    return 0;
}

bool solve(Soluzione& sol) {
    int x = 0; //MIN_VALUE
    while(x <= sol.n) {
        if(canAdd(x, sol)) {
            add(x, sol);

            if(isComplete(sol))
                return true;
            else if(solve(sol))
                return true;
            else {
                remove(sol);
            }
        }
        x++; // NEXT
    }
    return false;
}
