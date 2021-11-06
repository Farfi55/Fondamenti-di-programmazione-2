#ifndef ORDERED_LIST_H
#define ORDERED_LIST_H

#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::ostream;

template <class T>
class OrderedList : protected list<T> {
   public:
    void insert(const T& v);
    void remove(const T& v) { list<T>::remove(v); }
    bool find(const T& v) const { return list<T>::find(v); }
    bool empty() const { return list<T>::empty(); }

    template <class U>
    friend ostream& operator<<(ostream& o, const OrderedList<U>& ol);
};

template <class T>
void OrderedList<T>::insert(const T& v) {
    if (empty()) {
        // cout << v << " was added as the first element of the list\n";
        list<T>::push_front(v);
        return;
    }
    for (auto it = list<T>::begin(); it != list<T>::end(); it++) {
        if (v < *it) {
            // cout << v << " was added to the list before " << *it << "\n";
            list<T>::insert(it, v);
            return;
        }
    }
    // se non c'è nessun valore più grande di esso
    // cout << v << " was added to the end of the list\n";
    list<T>::push_back(v);
}

// template <class T>
// void OrderedList<T>::print() const {
//     for (auto it = list<T>::begin(); it != list<T>::end(); it++) {
//         cout << *it << " ";
//     }
// }

template <class U>
ostream& operator<<(ostream& o, const OrderedList<U>& ol) {
    std::cout << "{ ";
    for (int n : ol) {
        std::cout << n << ", ";
    }
    std::cout << "};\n";
    return o;
}

#endif
