// 10-12-2021 08:43

// esempio 1: [3, 5, 2, 1, -1] somma_target = 9
// out: [3, 5, 1]

// esempio 2: [1, 2, 1, -1] somma_target = 9   
// out: nessuna soluzione

// esempio 3: [3, 5, 4, 1, 1, -1] somma_target = 9
// soluzione di tipo base:

// a. [3, 5, 1]  vector di elementi
// b. [0, 1, 3]  vector degli indici
// c. [1, 1, 0, 1, 0]  vector di bool

// noi useremo b.


#include <iostream>
#include <vector>

using namespace std;


struct Soluzione {
    vector<int> sol; // indici degli elementi inseriti
    vector<int> elementi; // elementi in input
    int somma_target;
    int somma_corrente;

    Soluzione(vector<int> el, int st) : elementi(el), somma_target(st) {}


};

bool solve(Soluzione& sol);
bool canAdd(int x, const Soluzione& sol);
void add(int x, Soluzione& sol);
void remove(Soluzione& sol);
bool isComplete(const Soluzione& sol);


int main(int argc, const char** argv) {
    vector<int> elementi;
    cout << "inserisci elementi: ";
    int elem;
    cin >> elem;

    while(elem != -1) {
        elementi.push_back(elem);
        cin >> elem;
    }

    int somma_target;
    cout << endl << "inserisci target: ";
    cin >> somma_target;

    Soluzione s(elementi, somma_target);

    if(solve(s)) {
        cout << "Esiste una soluzione";
        for(int x : s.sol) {
            std::cout << sol.elementi[x] << std::endl;
        }
    }
    else
        cout << "Non esiste una soluzione";


}

bool solve(Soluzione& sol, int x) {
    while(x < sol.elementi.size()) {
        if(canAdd(x, sol)) {
            add(x, sol);

            if(isComplete(sol)) return true;
            if(solve(sol)) return true;

            remove(sol);
        }
        x++;
    }
    return false;
// alternativamente, con un for
    // for(; x < sol.elementi.size(); x++) {
    //     if(canAdd(x, sol)) {
    //         add(x, sol);

    //         if(isComplete(sol)) return true;
    //         if(solve(sol))) return true;

    //         remove(sol);
    //     }
    // }
}

// true se aggiungendo x non supero il target, false altrimenti
bool canAdd(int x, const Soluzione& sol) {

    // se abbiamo già usato questo elemento
    for(int y : sol.sol)
        if(y == x)
            return false; // non puoi aggiungerlo


    return (sol.somma_corrente + x <= sol.somma_target);
}


void add(int x, Soluzione& sol) {
    sol.somma_corrente += sol.elementi[x];
    sol.sol.push_back(x);
}

void remove(Soluzione& sol) {
    sol.somma_corrente -= sol.elementi[sol.sol.back()];
    sol.sol.pop_back();
}


bool isComplete(const Soluzione& sol) {
    return sol.somma_corrente == sol.somma_target;
}
