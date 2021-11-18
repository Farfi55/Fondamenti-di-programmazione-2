#include <math.h>
#include <iostream>
#include <list>
#include <queue>

using std::cout;
using std::endl;
using std::list;
using std::queue;


enum Direzione { SIN = 0, DES = 1 };

template<class T>
class AlberoB {

private:
    template <class U>
    struct SNodo {
        U vinfo; // valore informativo
        SNodo* ppadre; // puntatore al nodo padre
        SNodo* pfiglio[2]; // puntatori ai due figli, destro e sinistro

        SNodo(const U& inf) : vinfo(inf)
        {
            ppadre = pfiglio[SIN] = pfiglio[DES] = 0;
        }

        ~SNodo() {
            // distruzione ricorsiva di tutto il sotto-albero
            delete pfiglio[SIN];
            delete pfiglio[DES];
        }
    };

protected:
    SNodo<T>* pradice;

public:
    AlberoB() : pradice{ 0 } {}
    AlberoB(const T& a) {
        pradice = new SNodo<T>(a);
    }

    void inserisciFiglio(Direzione d, AlberoB<T>& AC);
    void inserisciFiglio(Direzione d, const AlberoB<T> AC);

    AlberoB<T> estraiFiglio(Direzione d);


    void modRadice(const T& a);

    void svuota() { delete pradice; }
    void annulla() { pradice = 0; }

    bool nullo() const { return pradice == nullptr; }

    AlberoB<T> copia() const;
    const T& radice() const { return *pradice; };

    // non ha figli
    bool foglia() const { return !nullo() && figlio(SIN).nullo() && figlio(DES).nullo(); }

    AlberoB<T> figlio(Direzione d) const;

    AlberoB<T> padre() const;

};



template<class T>
int profondita(AlberoB<T> A) {
    if(A.nullo()) return 0;
    else return 1 + __max(profondita(A.figlio(SIN)), profondita(A.figlio(DES)));
}



// SCRITTO MALISSIMO, ESPONENZIALE

template<class T>
bool bilanciato(const AlberoB<T>& A) {

    if(A.nullo()) return true;

    int Psin = profondita(A.figlio(SIN));
    int Pdes = profondita(A.figlio(DES));
    return abs(Psin, Pdes) <= 1
        && bilanciato(A.figlio(SIN))
        && bilanciato(A.figlio(DES));
}

// LINEARE
template<class T>
bool bilanciato(const AlberoB<T>& A, int& p) {

    if(A.nullo()) { p = 0; return true; }

    int Psin, Pdes;
    bool Bsin = bilanciato(A.figlio(SIN), p);
    bool Bdes = bilanciato(A.figlio(DES), p);
    p = 1 + __max(Psin, Pdes);
    return abs(Psin, Pdes) <= 1 && Bsin && Bdes;
}


// VISITE
/*
- visita in pre-ordine:  A B D E C F H I L G
- visita in post-ordine: D E B H L I F G C A
- visita simmetrica:     D B E A H F I L C G
- visita per livelli:    A B C D E F G H I L
*/


template<class T>
void visitaSimmetrica(AlberoB<T> A, list<T>& L) {
    if(!A.nullo()) {
        visitaSimmetrica(A.figlio(SIN), L);
        L.push_back(A.radice()); // valuta
        visitaSimmetrica(A.figlio(DES), L);
    }
}


template<class T>
void visitaPreOrdine(AlberoB<T> A, list<T>& L) {
    if(!A.nullo()) {
        L.push_back(A.radice()); // valuta
        visitaPreOrdine(A.figlio(SIN), L);
        visitaPreOrdine(A.figlio(DES), L);
    }
}


template<class T>
void visitaPostOrdine(AlberoB<T> A, list<T>& L) {
    if(!A.nullo()) {
        visitaPostOrdine(A.figlio(SIN), L);
        visitaPostOrdine(A.figlio(DES), L);
        L.push_back(A.radice()); // valuta
    }
}



typedef AlberoB<int> AlberoBInt;


void visitaPerLivelli(AlberoB<int> a) {
    if(a.nullo()) return;
    queue<AlberoBInt> q;
    q.push(a);
    while(!q.empty()) {
        AlberoBInt tmp = q.front();
        q.pop();
        cout << tmp.Radice() << " "; // valuta
        if(!a.figlio(SIN).nullo()) q.push((tmp.figlio(SIN)));
        if(!a.figlio(DES).nullo()) q.push((tmp.figlio(DES)));

    }
}



template<class T>
void Cerca(AlberoB<T> a, T v) {
    if(a.nullo() || a.radice() == v) return a;
    AlberoB<T> tmp = Cerca(a.figlio(SIN), v);
    if(!tmp.nullo()) return tmp;
    return Cerca(a.figlio(DES), v);
}



int main(int argc, char const* argv[])
{
    /*
    AlberoB<char> A(14);
    A.inserisciFiglio(SIN, 4);
    A.figlio(SIN).inserisciFiglio(SIN, 2);
    A.figlio(SIN).inserisciFiglio(DES, 3);

    A.inserisciFiglio(DES, 6);
    A.figlio(DES).inserisciFiglio(SIN, 5);
    A.figlio(DES).figlio(SIN).inserisciFiglio(SIN, 3);
    A.figlio(DES).figlio(SIN).inserisciFiglio(DES, 4);
    A.figlio(DES).figlio(SIN).figlio(DES), inserisciFiglio(DES, 2);

    A.figlio(DES).inserisciFiglio(DES, 1);
    */

    /*
              A
        B           C
      D   E       F    G
               H   I
                     L
    */

    AlberoB<char> A('A');
    A.inserisciFiglio(SIN, 'B');
    A.inserisciFiglio(DES, 'C');
    A.figlio(SIN).inserisciFiglio(SIN, 'D');
    A.figlio(SIN).inserisciFiglio(DES, 'E');
    A.figlio(DES).inserisciFiglio(SIN, 'F');
    A.figlio(DES).inserisciFiglio(DES, 'G');
    A.figlio(DES).figlio(SIN).inserisciFiglio(SIN, 'H');
    A.figlio(DES).figlio(SIN).inserisciFiglio(DES, 'I');
    A.figlio(DES).figlio(SIN).figlio(DES), inserisciFiglio(DES, 'L');


    std::cout << profondita(A) << std::endl;



    return 0;
}

