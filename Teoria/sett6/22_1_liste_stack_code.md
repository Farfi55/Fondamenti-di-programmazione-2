# Liste, stack e code

## Esercizio 1

#### Codice: Leggere una parola e determinare se è palindroma, usando le liste

```C++
#include "List.h"
#include "Iterator.h"
#include <iostream>
#include ...
using namespace std;

int main() {
	List<char> N;
	Iterator<char> sin(N), des(N);
	
	char c;
	while (cin>>c) {
		N.pushBack(c);
	}
	
    sin.moveAtFirst();
    des.moveAtLast();
    
    bool palindroma = true;
    while ((sin!=des) && palindroma) {
        if (*sin!=*des) { //if (sin.getCurrentValue()!=des.getCurrentValue))
            palindroma = false;
        } else {
            ++sin;
            if (sin!=des)
                --des;
        }
    } //end while
    
    if (palindroma)
        cout<<"E' palindroma"<<endl;
    else
        cout<<"Non e' palindroma"<<endl;
    return 0;
}
```

## Esercizio 2

#### Codice: Scrivere una funzione che, ricevuta una lista ed un intero x, scorre la lista per coppie di elementi consecutivi ed elimina il secondo nodo se la somma fra il primo ed il secondo è uguale ad x

```c++
void eliminaSomma(list<int>&, int x) {
    Iterator<int> it(L), it2(L);
    it.moveAtFirst(); it2.moveAtFirst();
    ++it2;
    
    while (!it2) {
        if ((*it)+(*it2) == x) {
            cout<<"Rimuovo "<<*it2<<endl;
            it2.remove();
        } else {
            ++it;
            ++it2;
        }
    }
}
```

## Sito da usare per references:
Cplusplus: https://www.cpluspluc.com/reference/

## Stack e code
### Stack: 

- Tecnica LiFo: last in, first out
  - Push: viene inserito alla fine
  - Pop: l'ultimo viene rimosso
  - Top: visualizza l'elemento alla fine

### Code: 

- Tecnica FiFo: first in, first out
  - Push: viene inserito all'inizio
  - Pop: l'ultimo elemento estratto è il piu' anziano
  - Back/Front: verifico gli elementi alla fine/inizio senza modificare la coda

```C++
template <class T>
class Stack: protected List<T> {
    int numElements;
    public:
    	Stack():numElement(0) {}
    	bool push(const T&);
    	void pop();
    	T top();
    	int size() const {return numElements;}
    	using List<T>::empty; //rende visibile empty di List
    	bool full() const {return false;}
}

template <class T>
bool Stack<T>::push(const T& v) {
    List<T>::pushFront(v);
    ++numElements;
    return true;
}

template <class T>
void pop() {
    assert(!empty());
    --numElements;
    T v;
    List<T>::popFront(v);
}

template <class T>
T Stack<T>::top() {
    assert(!empty());
    T v = List<T>::front()->getValue;
    return v;
}
```

## Codice: Letta una espressione parentesizzata (una stringa), determinare se essa è ben parentesizzata (ad ogni parentesi aperta corrisponde una parentesi chiusa). Stampare, inoltre, la coppia di posizioni di apertura/chiusura parentesi

Esempio: ((x+2) + (y-3) * ((k^2) - 2x))

```c++
int main() {
    string expr;   
    Stack<int> s;
    getline(cin,expr);
    bool esci = false;
    
    for(int i=0; i<expr.length(); i++) {
        if (expr[i] == '(')
            s.push(i);
        else (expr[i] == ')') {
            if (s.empty())
                esci = true;
            else {
                int pos = s.top();
            	s.pop();
            	cout<<"La parentesi in posizione "<<pos<<" si chiude in posizione "<<i<<endl;
            }
        }
    }
    if ((esci == true) || (!s.empty()))
        cout<<"L'espressione non e' ben parentesizzata"<<endl;
    else
        cout<<"L'espressione è ben parentesizzata"<<endl;
    cout<<"Fine elaborazione."<<endl;
}
```
