# Vector

Vector <- (containers)

Cosa servirà:

- Template
- Incapsulamento *(information hiding)*
- memoria dinamica

## Progettazione

- `Puntatore per array din.`
- Size: n. di elementi *"significativi"*
- Capacità: celle disponibili

## Dichiarazione

```cpp
#ifndef VECTOR_H
#define VECTOR_H

template <class R>
class Vector{
	template<class R>
	friend ostream& operator<< (ostream& out, const Vector<R>& v);
	template<class R>
	friend istream& operator>> (istream& in, Vector<R>& v);


	R* vec;
	unsigned int size;
	unsigned int cap;

public:
	// INTERFACCIA 
	Vector(); // costruttore di default
	Vector(const Vector<R>&); // costruttore di copia

	~Vector(); // distruttore

	unsigned int size() const { return size; };
	unsigned int capacity() const { return cap; };

	R& operator[](unsigned int i); // versione (default, read-write)
	R operator[](unsigned int i) const; // versione per oggetti costanti (read-only)

	Vector& operator= (const Vector<R>&); // overload dell'assegnazione


	void pushBack(const R&); // aggiungi elemento in fondo
	const R& back() const; // leggi ultimo elemento
	void popBack(); // elimina ultimo elemento
	void reserve(unsigned int size);
	void resize (unsigned int size);


};


#endif
```

## Implementazione

```cpp
template<class R>
Vector<R>::vector(){
	size = 0;
	cap = 1; // DISCUTIBILE
	vec = new R[cap];	
}

template<class R>
Vector<R>::Vector(const Vector<R>& v){
	size = v.size;
	cap = v.cap;
	vec = new R[cap];

	for (int i = 0; i < size; ++i)
		vec[i] = v.vec[i];
}

template<class R>
Vector<R>::~Vector(){
	delete [] vec;
}

//operatori

#include <assert.h>

template<class R>
R& Vector<R>::operator[](unsigned int i){
	// ci assicura che l'indice sia valido
	assert(i >= 0 && i < size); 
	return vec[i];
}

template<class R>
R Vector<R>::operator[](unsigned int i) const {
	assert(i >= 0 && i < size);
	return vec[i];
}

template<class R>
R Vector<R>::operator=(const Vector<R>& v) {
	if(this != &v){
		cap = v.cap;
		
		if(size != v.size)
		{
			size = v.size;
			delete [] vec;
			vec = new R[cap];
		}

		for(int i = 0; i < size; ++i)
			vec[i] = v.vec[i];
	}
	return *this;
}


template<class R>
void Vector<R>::pushBack(const R& e){

	if(size == cap)
		reserve(cap*2);

	vec[size] = e;
	size++;	
}

template<class R>
const R& Vector<R>::back() const {
	assert(size > 0);
	return vec[size - 1];
}


template<class R>
void Vector<R>::popBack(){
	if(size > 0);
		size--;
}

// imposta la capacità
template<class R>
void Vector<R>::reserve(unsigned int newSize){
	if(newSize > cap){
		cap = newSize;
		R* tmp = new R[cap];

		for(int i = 0; i < size; i++){
			tmp[i] = vec[i];
		}

		delete [] vec;
		vec = tmp;
	}
}


template<class R>
void Vector<R>::resize(unsigned int newSize){
	reserve(newSize);
	size = newsize;
}


template<class R>
ostream& operator<<(ostream& out, const Vector<R>& v){
	out << "(";
	for(int i = 0; i < v.size; ++i){
		out << " " << v[i];
	}
	out << " )\n";
	return out;
}

```

## utilizzo

```cpp
#include <iostream>
#include "Vector.h"

int main(){
	Vector<int> v;
	for(int i = 0; i < 10; ++i)
		v.pushBack(i);

	// qui so quanto sarà la dimensione necessaria, conveniva usare un reserve invece di fare più ridimensionamenti
	// v.reserve(10);
	

	cout << "svuoto l'array ";

	while(v.size() > 0) {
		cout << v.back() << " ";
		v.popBack();
	} 
	// stampa 9 8 7 ... 0


	Vector<char> vz;

	for (int i = 0; i < 10; i++){
		char c;
		cin >> c;
		v2.pushBack(c);
	}

}
```
