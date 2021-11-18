#include "AlberoB.h"
#include <iostream>
#include <string>
#include <queue>
#include <list>

using namespace std;


template <class T>
AlberoB<T> cerca(const AlberoB<T>& a, T v) {
    if(a.nullo() || a.radice() == v)
        return a;

    // a questo punto sono in un sottoalbero che non ha v come valore 
//informativo e non è nullo
    AlberoB<T> temp = cerca(a.figlio(SIN), v);
    if(!temp.nullo())
        return temp;
    // a questo punto so che nel sottoalbero sinistro non c'era un albero con 
// v come valore informativo
    return cerca(a.figlio(DES), v);
}

typedef AlberoB<int> AlberoBInt;


void visitaPerLivelli(const AlberoB<int>& a) {
    if(a.nullo())
        return;

    std::queue<AlberoBInt> q;
    q.push(a);

    while(!q.empty()) {
        AlberoBInt temp = q.front(); // q.front() restituisce l'oggetto in 
//testa alla coda SENZA RIMUOVERLO
        q.pop();			 // q.pop() rimuove l'oggetto in testa alla coda

// elaborare l'albero temp
        std::cout << temp.radice() << ' ';

        if(!temp.figlio(SIN).nullo())
            q.push(temp.figlio(SIN));
        if(!temp.figlio(DES).nullo())
            q.push(temp.figlio(DES));
    }
}


int main(int argc, char const* argv[])
{

    int radice;
    cin >> radice;
    if(radice == -1) return 0;

    AlberoB<int> albero(radice);

    while(true) {
        string input;
        cin >> input;
        if(input == "-1") break;

        int sep = input.find(':');
        const int val = stoi(input.substr(0, sep));
        const int padre = stoi(input.substr(sep + 1, input.size() - 1 - sep));

        char dir_input;
        Direzione dir;

        cin >> dir_input;

        if(dir_input == 's') dir = SIN;
        else if(dir_input == 'd') dir = DES;

        // cout << "val: " << val << ", padre: " << padre << ", (0:sin, 1:des): " << dir << endl;

        auto sotto_albero_padre = cerca(albero, padre);
        if(!sotto_albero_padre.nullo()) {
            AlberoB<int> nuovo_ramo(val);

            sotto_albero_padre.insFiglio(dir, nuovo_ramo);
        }
    }


    visitaPerLivelli(albero);


    return 0;
}
