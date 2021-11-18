#ifndef INSIEME_H
#define INSIEME_H

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class insieme {
    vector<T> s;

public:
    insieme() {};
    insieme(const insieme<T>& set) : s(set.s) {};
    int size() const { return s.size(); }

    bool isIn(const T& e) const;
    bool add(const T& e);
    bool remove(const T& e);
    bool empty() const { return s.size() == 0; }

    insieme<T>& unionTo(const insieme<T>& set) const;
    insieme<T>& intersectTo(const insieme<T>& set) const;
    insieme<T>& differenceWith(const insieme<T>& set) const;
    insieme<T>& simmetricDifferenceWith(const insieme<T>& set) const;

    template <class U>
    friend ostream& operator<<(ostream& o, const insieme<U>& set);
};

// template<class T>
// bool insieme<T>::add(const T& elemento) {
// 	if(!isIn(elemento)) {
// 		s.push_back(elemento);
// 		return true;
// 	}
// 	else return false;
// }

// oppure

template <class T>
bool insieme<T>::add(const T& e) {
    // se l'iteratore restituito da find è diverso dall'ultimo elemento
    // significa che abbia trovato qualcosa
    if(find(s.begin(), s.end(), e) != s.end()) return false;



    s.push_back(e);
    return true;

}

template <class T>
bool insieme<T>::remove(const T& e) {
    auto it = find(s.begin(), s.end(), e);
    if(it == s.end())
        return false;  // non è stato trovato l'elemento
    else {
        s.erase(it);
        return true;
    }
}

template <class T>
bool insieme<T>::isIn(const T& e) const {
    return find(s.begin(), s.end(), e) != s.end();
}

// paragonabile ad un OR logico
// esempio utilizzo
// IN:  insA:   (1,3,4,5)
//      insB:   (2,3,4)
// OUT: insOut: (1,2,3,4,5)
template <class T>
insieme<T>& insieme<T>::unionTo(const insieme<T>& set) const {
    // visto che l'operazione resta invariata
    // Ottimizzo invertendo l'insieme "this" e l'insieme parametro
    // quando quest'ultimo è più grande
    if(set.size() > size()) return set.unionTo(*this);

    insieme<T>* tmp = new insieme<T>(set);

    for(int i = 0; i < size(); i++) tmp->add(s[i]);

    return *tmp;
}

// paragonabile ad un AND logico
// esempio utilizzo
// IN:  insA:   (1,3,4,5)
//      insB:   (2,3,4)
// OUT: insOut: (3,4)
template <class T>
insieme<T>& insieme<T>::intersectTo(const insieme<T>& set) const {
    auto* tmp = new insieme<T>();
    for(int i = 0; i < s.size(); i++) {
        if(find(set.s.begin(), set.s.end(), s[i]) != set.s.end())
            tmp->add(s[i]);
    }
    return *tmp;
}

// paragonabile ad (insA && !insB)
// esempio utilizzo
// IN:  insA:   (1,3,4,5)//      insB:   (2,3,4)
// OUT: insOut: (1,5)
template <class T>
insieme<T>& insieme<T>::differenceWith(const insieme<T>& set) const {
    insieme<T>* tmp = new insieme<T>(*this);

    for(int i = 0; i < set.size(); i++) {
        const T e = set.s[i];
        tmp->remove(e);
    }

    return *tmp;
}

// non richiesto dal prof ma utile comunque
// funziona come un Exclusive OR logico, applicato agli insiemi
// esempio utilizzo
// IN:  insA:   (2,3,4)
//      insB:   (1,3,4,5)
// OUT: insOut: (1,2,5)
template <class T>
insieme<T>& insieme<T>::simmetricDifferenceWith(const insieme<T>& set) const {
    // visto che l'operazione resta invariata
    // Ottimizzo invertendo l'insieme "this" e l'insieme parametro
    // quando quest'ultimo è più grande
    if(set.size() > size()) return set.differenceWith(*this);

    insieme<T>* tmp = new insieme<T>(set);

    for(int i = 0; i < size(); i++) {
        auto it = find(tmp->s.begin(), tmp->s.end(), s[i]);
        if(it == tmp->s.end()) {  // non trovato
            const T e = s[i];
            tmp->s.push_back(e);
        }
        else {  // trovato
            tmp->s.erase(it);
        }
    }
    return *tmp;
}

template <class U>
ostream& operator<<(ostream& o, const insieme<U>& set) {
    for(int i = 0; i < set.size(); i++) {
        o << set.s[i] << " ";
    }
    return o;
}

#endif
