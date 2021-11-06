#include "CodaEreditaria.h"

#include <algorithm>

void CodaEreditaria::aggiungi(char c) {
    // se find restituisce accepted.end() allora c non è presente in accepted
    if (find(accepted.begin(), accepted.end(), c) == accepted.end()) return;

    if (c == 'p') {
        push_front(c);
        return;
    }

    if (c == 'g') {
        for (auto it = begin(); it != end(); it++) {
            if (*it == 't') {
                insert(it, c);
                return;
            }
        }
    }
    push_back(c);
}

char CodaEreditaria::prossimo() const { return front(); }

void CodaEreditaria::rimuovi() { pop_front(); }

ostream& operator<<(ostream& o, const CodaEreditaria& coda) {
    for (auto it = coda.begin(); it != coda.end(); it++) {
        o << (*it) << ", ";
    }
    return o;
}
