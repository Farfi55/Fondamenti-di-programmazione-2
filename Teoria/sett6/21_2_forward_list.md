# Liste (Forward List)

al conrtario dei vector che sono disposti nello stesso spazio di memoria,  
la Forward list non è cache friendly per via dei numerosi salti effettuati, dato da come vengono memorizzati i valori, cioè che ogni *nodo* ha un valore e un puntatore al prossimo nodo

Questo ci permette di cancellare e aggiungere elementi in tempo costante semplicemente cambiando dove punta il puntatore del prossimo nodo.

Per accedere agli elementi della lista abbiamo bisogno di un puntatore al primo nodo

Per questioni di efficenza teniamo un riferimento anche all'ultimo elemento della lista

## Pros

- Modifica della struttura molto efficente
- Occupa solo lo spazio strettamente necessario

## Cons

- Accesso degli elementi non costante
- non è cache friendly
- Avendo un nodo si espone tutto il resto della Lista
- Ogni Nodo include più spazio per via del puntatore

## Esempio implementazione

```cpp
template<class T>
class Node{
private:
	T value;
	Node<T>* nextNode;
public:
	friend class List<T>;
	Node (const T& v): nextNode{0}, value{v} {}
	T get() const { return value; }
	Node<T>* nextNode() const { return nextNode; }
};
```

___

```cpp
template<class T>
class List{
protected:
	Node<T>* first;
	Node<T>* last;
	Node<T>* newNode(const T&);

public:
	// costruttori
	List(): first{0}, last{0} {}
	List(const List<T>& list) {}
	// distruttore
	~List();

	// interfaccia
	void pushFront(T& v);
	void pushBack(T& v);

	bool popFront();
	bool popBack();

	bool empty();
	bool find(const T& ) const;
	void delNode(Node<T>& );
	void remove(const T&);
	Node<T>* front();
}
```

___

```cpp
template<class T>
bool List::empty() const { return first == nullptr; }
```

```cpp
template<class T>
List::~List(){
	if(first == nullptr) return;

	Node<T>* curr = first;
	Node<T>* tmp;

	while(curr != null){
		tmp = curr;
		curr = curr->nextNode();
		delete tmp;
	}
}
```

```cpp
template<class T>
Node<T>* List<T>::newNode(const T& v) {
	Node<T>* ptr = new Node<T>(v);
	assert(ptr != 0);
	return ptr;
}
```

```cpp
template<class T>
void List<T>::pushFront(const T& v){
	Node<T>* n = newNode<T>(v);
	if(empty()){
		fist = last = n;
	}
	else {

		n->nextNode = first;
		first = n;
	}
}
```

```cpp
template<class T>
void List<T>::pushBack(const T& v){
	Node<T>* n = newNode<T>(v);
	if(empty()){ 
		fist = last = n;
	}
	else {
		last->nextNode = n;
		last = n;
	}
}
```

```cpp
template<class T>
bool List<T>::popFront(T& v){
	if(empty())
		return false;

	Node<T>* tmp = fist;
	if(first == last) {
		first = last = nullptr;
	}
	else{
		first = first->nextNode;
	}
	v = tmp->value;
	delete tmp;
	return true;
}

```
<!-- TODO: IMPLEMENTARE popBack() -->
```cpp

```

```cpp
template<class T>
bool List<T>::find(const T& v) const {
	Node<T>* ptr = first;
	while(ptr != 0){
		if(ptr->value == v)
			return true;
		ptr = ptr->next;
	}
	return false;
}
```

```cpp
template<class T>
void List<T>::deleteNode(Node<T>& pos) const {
	assert(!empty());
	if(pos == first){
		first = pos->nextNode;
		delete pos;
		pos = first;
	}
	else {
		Node<T>* prec = first;
		while(prec->nextNode != pos) prec = prec->nextNode();
		Node<T>* tmp = pos;
		prec->nextNode = pos->nextNode;
		if(pos==last)
			last=prec;
		delete pos;
		pos = prec->nextNode;

	}
}
```
