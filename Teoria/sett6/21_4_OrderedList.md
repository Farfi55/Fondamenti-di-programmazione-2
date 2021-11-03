# Ordered list

senza riscrivere tutto quanto, possiamo scrivere una classe `ordered List` andando a derivare dalla classe List

deriviamo da List con il modificatore protected, perchè non vogliamo che siano accessibili tutti i metodi di List, anzi vogliamo cambiare il funzionamento di alcuni

## Esempio

```cpp
template<class T>
class OrderedList: protected List<T>{
	public:
		void insert(const T& v);
		void remove(const T& v) { List<T>::remove(v); }
		bool find(const T& v) const { List<T>::find(v); }
		bool empty(const T& v) const { List<T>::empty(v); }


}
```
