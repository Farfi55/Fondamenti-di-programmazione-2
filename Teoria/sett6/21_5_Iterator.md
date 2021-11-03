# Iterator

permettermi di accedere alla lista con alcune restizione, in modo da proteggere da usi sbagliati

deve essere `friend` in `Node` e `List`

## esempio implementazione

```cpp
template <class T>
class Iterator{
private:
	Node<T>* corr;
	Node<T>* prec;
	List<T>& l;

public:
	Iterator(List<T>& lista):l(lista), corr(lista.first), prec(0) {};
	T getCurrentValue();
	T operator*(); // .... return corr->value
	bool operator!(); // per la funzione empty
	void operator++(); // per farlo avanzare
	void operator--(); // per farlo andare indietro
	void moveAtFirst(); // simile a begin()
	void moveAtLast(); // simile a end() di STL
	void insert(const T& val); // inserisci val nel punto corrente
	void remove(); // rimuovi elemento nel punto corrente
	
}
```

```cpp
int main(){
	List<int> l;
	Iterator<int> it(l);
	// riempo l
	cout << *it;

	if(!it)
		cout << "Not empty!\n";
}

```
