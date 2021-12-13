/**
13-12-2021 09:06

dato un insieme di monete (numeri)
dividere in due sottoinsiemi in modo tale da minimizzare la diff. delle
loro somme
*/

// esempio: 3 5 12 9
// sol: 3, 12; 5, 9 


// determinare la differenza minima

/*
  calcolare tutte le somme possibili

  O(n*somma)
*/

// vector<int> comb; //(dim) per le combinazioni
// vector<bool> possibiliSomme(i); // (dim somma tot, 0...somma) per le somme possibili

// sol: il primo true vicino a somma/2

// dall'esembio:
// somma di tutti gli elementi = 29
// possibiliSomme(29, false);
// possibiliSomme[0] = true;

#include <vector>
using namespace std;

int main(int argc, char const* argv[])
{
    vector<int> coins;
    // leggi coins
    int somma = sum(coins);

    bool possibiliSomme[somma + 1] = { false };
    possibiliSomme[0] = true;
    for(int coin : coins)
        // con un for inverso così da non passare sugli elementi appena calcolati
        for(int j = somma - coin; j >= 0; --j) {
            if(possibiliSomme[j])
                possibiliSomme[j + coin] = true;
        }

    int i;
    bool trovato = false;
    for(i = somma / 2; i >= 0 && !trovato; --i) {
        if(possibiliSomme[i]) {
            std::cout << "Minima Diff: " << (somma - i) - i << std::endl;
            trovato = true;
        }
    }

    return 0;
}


