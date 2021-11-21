#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <tuple>
#include <string>

#include "../../../Implementazioni/AlberoB/AlberoB.h"

using namespace std;


bool piramideSalda(const AlberoB<int>& a, int pesoMassimo);

bool ogniPercorsoRadiceFoglia(const AlberoB<int>& a, int max, int sommaCorrente);


bool pariEDispari(const AlberoB<int>& a);

int sommaPath(const AlberoB<int>& a);

int sommaPath(const AlberoB<int>& a, int sommaCorrente);

AlberoB<int> vecToAlbero(vector<int> vettore);

void printPerLivelli(const AlberoB<int>& a);


bool fogliePosEqFoglieNeg(const AlberoB<int>& a);

int posNegDifference(const AlberoB<int>& a);


bool sommaLivelliAdiacenti(const AlberoB<int> a, int max);

bool vocaliEConsonanti(const AlberoB<char>& a);


int main(int argc, char const* argv[])
{

    // AlberoB<int> a(4);

    // AlberoB<int> b(3);
    // AlberoB<int> c(2);
    // a.insFiglio(SIN, b);
    // a.insFiglio(DES, c);

    // AlberoB<int> d(2);
    // AlberoB<int> e(1);
    // b.insFiglio(SIN, d);
    // b.insFiglio(DES, e);

    // AlberoB<int> f(4);
    // AlberoB<int> g(2);
    // c.insFiglio(SIN, f);
    // c.insFiglio(DES, g);

    // AlberoB<int> h(3);    
    // d.insFiglio(SIN, h);

    AlberoB<int> a(2);

    AlberoB<int> b(3);
    AlberoB<int> c(4);
    a.insFiglio(SIN, b);
    a.insFiglio(DES, c);

    AlberoB<int> d(5);
    AlberoB<int> e(1);
    b.insFiglio(SIN, d);
    b.insFiglio(DES, e);

    AlberoB<int> f(3);
    c.insFiglio(SIN, f);

    printPerLivelli(a);

    if(ogniPercorsoRadiceFoglia(a, 15, 0)) {
        cout << "nessun percorso supera il massimo" << endl;
    }

    if(pariEDispari(a))
        cout << "Pari e dispari" << endl;

    cout << sommaPath(a) << endl;
    cout << endl << endl;



    vector<int> vec = { 17,12,22,1,3,5,7 };
    AlberoB<int> a2 = vecToAlbero(vec);
    printPerLivelli(a2);
    if(ogniPercorsoRadiceFoglia(a, 50, 0)) {
        cout << "nessun percorso supera il massimo" << endl;
    }
    if(pariEDispari(a2))
        cout << "Pari e dispari" << endl;

    cout << endl << endl;



    // 3 nodi positivi, 3 nodi negativi
    vector<int> vec3 = { 17,-12,-22,1,-3, 5 };
    AlberoB<int> a3 = vecToAlbero(vec3);

    if(fogliePosEqFoglieNeg(a3))cout << "numero uguale di foglie positive e negative\n";
    else cout << "numero diverso di foglie positive e negative\n";

    // aggiungendo un nodo negativo, il numero di nodi
    // positivi e negativi non sara' piu' lo stesso
    auto figlioFoglia = AlberoB<int>(-1);
    a3.figlio(DES).insFiglio(DES, figlioFoglia);

    if(fogliePosEqFoglieNeg(a3))
        cout << "numero uguale di foglie positive e negative\n";
    else cout << "numero diverso di foglie positive e negative\n";
    cout << endl << endl;

    cout << "sommaLivelliAdiacenti(a3, max: -10): ";
    cout << (sommaLivelliAdiacenti(a3, -10) ? "true\n" : "false\n");
    // i risultati sono:
    // lvl(1:2): -17  = 17 - 12 - 22
    // lvl(2:3): -32  = -12 - 22 + 1 - 3 + 5 - 1




    return 0;
}


typedef AlberoB<int> AlberoBInt;

/*
Piramide salta = true
sse la somma dei valori su ogni livello è <= pesoMassimo
 */

bool piramideSalda(const AlberoB<int>& a, int pesoMassimo) {

    if(a.nullo())
        return true;

    queue<AlberoBInt> qAlberi;
    queue<int> qLivelli;

    qAlberi.push(a);
    qLivelli.push(1);

    int somma = 0;
    int livelloCorrente = 1;

    while(!qAlberi.empty()) {
        AlberoBInt temp = qAlberi.front(); // qAlberi.front() restituisce l'oggetto in 
        //testa alla coda SENZA RIMUOVERLO
        qAlberi.pop();			 // qAlberi.pop() rimuove l'oggetto in testa alla coda

        // elaborare l'albero temp
        int livelloTmp = qLivelli.front();
        qLivelli.pop();

        if(livelloTmp == livelloCorrente)
            somma += temp.radice();
        else {
            if(somma > pesoMassimo) {
                return false;
            }
            livelloCorrente++;
            somma = temp.radice();
        }

        if(!temp.figlio(SIN).nullo()) {
            qAlberi.push(temp.figlio(SIN));
            qLivelli.push(livelloTmp + 1);
        }
        if(!temp.figlio(DES).nullo()) {
            qAlberi.push(temp.figlio(DES));
            qLivelli.push(livelloTmp + 1);
        }
    }

    if(somma > pesoMassimo) return false;
    else return true;
}



bool ogniPercorsoRadiceFoglia(const AlberoB<int>& a, int max, int sommaCorrente) {
    if(a.nullo()) return true;

    sommaCorrente += a.radice();
    if(a.foglia())
        return sommaCorrente <= max;

    return ogniPercorsoRadiceFoglia(a.figlio(SIN), max, sommaCorrente)
        && ogniPercorsoRadiceFoglia(a.figlio(DES), max, sommaCorrente);
}


bool ogniPercorsoRadiceFoglia(const AlberoB<int>& a, int max) {
    if(a.nullo()) return true;

    max -= a.radice();
    if(a.foglia())
        return (max >= 0);

    return ogniPercorsoRadiceFoglia(a.figlio(SIN), max)
        && ogniPercorsoRadiceFoglia(a.figlio(DES), max);
}



bool pariEDispari(const AlberoB<int>& a) {
    if(a.nullo())
        return true;

    queue<AlberoBInt> qAlberi;
    queue<int> qLivelli;

    qAlberi.push(a);
    qLivelli.push(1);


    while(!qAlberi.empty()) {
        AlberoBInt temp = qAlberi.front();
        qAlberi.pop();

        // elaborare l'albero temp
        int livelloTmp = qLivelli.front();
        qLivelli.pop();

        if((temp.radice() + livelloTmp) % 2 != 0)
            return false;

        if(!temp.figlio(SIN).nullo()) {
            qAlberi.push(temp.figlio(SIN));
            qLivelli.push(livelloTmp + 1);
        }
        if(!temp.figlio(DES).nullo()) {
            qAlberi.push(temp.figlio(DES));
            qLivelli.push(livelloTmp + 1);
        }
    }

    return true;
}


int sommaPath(const AlberoB<int>& a) {
    return sommaPath(a, 0);
}


int sommaPath(const AlberoB<int>& a, int sommaCorrente) {
    if(a.nullo()) return 0;

    sommaCorrente = sommaCorrente * 10 + a.radice();

    if(a.foglia()) return sommaCorrente;
    else return sommaPath(a.figlio(SIN), sommaCorrente) +
        sommaPath(a.figlio(DES), sommaCorrente);
}


AlberoB<int> vecToAlbero(vector<int> vettore) {
    AlberoB<int> albero(vettore[0]);
    vector<AlberoB<int>> alberi;
    alberi.push_back(albero);

    for(int i = 1; i < vettore.size(); i++) {
        AlberoB<int> newAlbero(vettore[i]);
        alberi.push_back(newAlbero);

        Direzione dir = Direzione((i + 1) % 2);
        alberi[(i - 1) / 2].insFiglio(dir, newAlbero);
    }

    return albero;
}



void printPerLivelli(const AlberoB<int>& a) {
    if(a.nullo())
        return;

    queue<AlberoBInt> qAlberi;
    queue<int> qLivelli;

    qAlberi.push(a);
    qLivelli.push(1);

    int livelloPrec = 1;

    while(!qAlberi.empty()) {
        AlberoBInt temp = qAlberi.front();
        qAlberi.pop();

        // elaborare l'albero temp
        int livelloTmp = qLivelli.front();
        qLivelli.pop();

        if(livelloTmp > livelloPrec) {
            cout << endl;
            livelloPrec++;
        }

        cout << temp.radice() << ' ';

        if(!temp.figlio(SIN).nullo()) {
            qAlberi.push(temp.figlio(SIN));
            qLivelli.push(livelloTmp + 1);
        }
        if(!temp.figlio(DES).nullo()) {
            qAlberi.push(temp.figlio(DES));
            qLivelli.push(livelloTmp + 1);
        }
    }

    cout << endl;
}



// restituisce true solo se il numero di foglie con val < 0 
// è uguale al numero di foglie con val >= 0

bool fogliePosEqFoglieNeg(const AlberoB<int>& a) {
    int difference = 0;
    return (posNegDifference(a) == 0);
}

// helper function
int posNegDifference(const AlberoB<int>& a) {
    if(a.nullo()) return 0;
    else
        return ((a.radice() >= 0) ? 1 : -1)
        + posNegDifference(a.figlio(SIN))
        + posNegDifference(a.figlio(DES));
}

// restituisce true se la somma di ogni coppia di livelli adiacenti non superano il max
bool sommaLivelliAdiacenti(const AlberoB<int> a, int max) {
    if(a.nullo())
        return true;

    queue<AlberoBInt> qAlberi;
    queue<int> qLivelli;

    qAlberi.push(a);
    qLivelli.push(1);

    int livelloCorrente = 1;

    int sumPrec = 0, sumCurr = 0;

    while(!qAlberi.empty()) {
        // valore
        AlberoBInt temp = qAlberi.front();
        qAlberi.pop();

        // livello (depth)
        int livelloTmp = qLivelli.front();
        qLivelli.pop();

        if(livelloTmp > livelloCorrente) {
            // cout << "sum prec: " << sumPrec << endl;
            // cout << "sum curr: " << sumCurr << endl;
            if(livelloCorrente > 1 && sumPrec > max) return false;
            sumPrec = sumCurr;
            sumCurr = 0;
            livelloCorrente++;
        }
        sumPrec += temp.radice();
        sumCurr += temp.radice();


        if(!temp.figlio(SIN).nullo()) {
            qAlberi.push(temp.figlio(SIN));
            qLivelli.push(livelloTmp + 1);
        }
        if(!temp.figlio(DES).nullo()) {
            qAlberi.push(temp.figlio(DES));
            qLivelli.push(livelloTmp + 1);
        }
    }
    // cout << "sum prec: " << sumPrec << endl;
    // cout << "sum curr: " << sumCurr << endl;

    return (sumPrec <= max);

}




    /*
      Supponiamo che ogni percorso dalla radice alla foglia costituisca una parola
    ret true:
        se ogni parola ha un numero di vocali e consonanti che differiscono al più di uno.
    si supponga che la parola contenga solo lettere che siano minuscole

    */
    // bool vocaliEConsonanti(const AlberoB<char>& a);


