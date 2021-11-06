#ifndef CODA_EREDITARIA_H
#define CODA_EREDITARIA_H
#include <iostream>
#include <list>
#include <vector>
using namespace std;

// se eredito public posso usare le funzioni di list nel main e non voglio che
// questo sia possibile (potrei fare push_back('a'))

class CodaEreditaria : private list<char> {
   public:
    void aggiungi(char n);
    char prossimo() const;
    void rimuovi();
    int size() const;

    friend ostream& operator<<(ostream& o, const CodaEreditaria& coda);

   private:
    vector<char> accepted = {'b', 'c', 'd', 'f', 'g', 'h', 'l', 'm',
                             'n', 'p', 'q', 'r', 's', 't', 'v', 'z'};
};

#endif
