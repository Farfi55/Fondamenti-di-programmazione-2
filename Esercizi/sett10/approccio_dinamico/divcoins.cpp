#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int divcoins_greedy(vector<int>& coins);
int divcoins(vector<int>& coins);

int main(int argc, char const* argv[])
{

    // 10 10 6 5 1

    // 5 3 12 9

    vector<int> coins;

    {
        int input;
        while(true) {
            cin >> input;
            if(input == -1) break;
            coins.push_back(input);
        }
    }


    cout << "differenza usando la tecnica:" << endl;

    int diff_golosa = divcoins_greedy(coins);
    cout << "- golosa:   " << diff_golosa << endl;

    int diff_dinamica = divcoins(coins);
    cout << "- dinamica: " << diff_dinamica << endl;

    return 0;
}


// IMPLEMENTAZIONE GOLOSA

// fa un sort su coins e poi cerca di minimizzare la differenza
int divcoins_greedy(vector<int>& coins) {
    sort(coins.begin(), coins.end(), greater<int>());

    int difference = 0;

    for(int i = 0; i < coins.size(); i++) {
        if(difference <= 0)
            difference += coins[i];
        else difference -= coins[i];
        // cout << difference << endl;
    }
    return difference;
}


// IMPLEMENTAZIONE DINAMICA

int divcoins(vector<int>& coins) {

    // calcoliamo la differenza massima, sommando tutte le monete
    int somma;
    for(int coin : coins)
        somma += coin;


    // ci generiamo tutte le somme possibili usando le coins
    // iniziamo impostandole tutte false
    vector<bool> somme_possibile(somma, false);

    // tranne 0, che rappresenta non prendere nessuna moneta
    somme_possibile[0] = true;

    // per ogni moneta 
    for(int coin : coins)
        for(int i = somma - 1; i >= 0; --i)
            if(somme_possibile[i]) { // iteriamo su ogni possibile somma
                somme_possibile[i + coin] = true;
                // dalla quale possiamo aggiungere il valore di coin 
                // e generare un'altra soluzione valida
                // sulla quale sarà poi possibile aggiungere altre monete,
                // finchè ne rimangono
            }

    // la soluzione ottima sarebbe somma_possibile[somma/2],
    // ma non è detto che sià possibile, quindi iniziando da questo elemento
    // andiamo avanti finchè non troviamo il primo possibile, 
    // che sarà la soluzione ottima per questo problema
    for(int i = somma / 2; i >= 0; --i)
        if(somme_possibile[i])
            return somma - (i * 2);

    // non arriva mai qui, visto che somme_possibile[0] è sempre true
    return somma;
}


/*
esempio: 1 (somma dispari min: 0)

        10 T : somma
        9
        8  T
        7
        6  T
        5  F   <-
        4  T
        3
        2  T
        1
        0  T

        10 - 4 - 4 = 2 giusto

esempio: 2 (somma pari min: 1)
        11 T : somma
        10
        9
        8  T
        7
        6  T
        5  T   <-
        4
        3  T
        2
        1
        0  T

    11 - 5 - 5 = 1 giusto

*/


