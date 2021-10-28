#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <assert.h>
using namespace std;


template <class R>
class Vector{

	R* _vec;
	unsigned int _size;
	unsigned int _cap;

public:
	// INTERFACCIA 
	Vector(); // costruttore di default
	Vector(const Vector<R>&); // costruttore di copia
	
	~Vector(); // distruttore
	
	unsigned int size() const { return _size; }
	unsigned int capacity() const { return _cap; }
	
	R& operator[](unsigned int i); // versione (default, read-write)
	R operator[](unsigned int i) const; // versione per oggetti costanti (read-only)
	
	Vector<R>& operator= (const Vector<R>&); // overload dell'assegnazione
	
	void pushBack(const R&); // aggiungi elemento in fondo
	const R& back() const; // leggi ultimo elemento
	void popBack(); // elimina ultimo elemento
	void reserve(unsigned int size);
	void resize (unsigned int size);
};

// costruttori
template<class R>
Vector<R>::Vector(){ // di base
	_size = 0;
	_cap = 2; // DISCUTIBILE
	_vec = new R[_cap];	
}


template<class R>
Vector<R>::Vector(const Vector<R>& v){ // di copia
	_size = v._size;
	_cap = v._cap;
	_vec = new R[_cap];
	for (int i = 0; i < _size; ++i)
		_vec[i] = v._vec[i];
}


// distruttore
template<class R>
Vector<R>::~Vector(){
	delete [] _vec;
}


// * implementazione overload operatori

template<class R>
R& Vector<R>::operator[](unsigned int i){
	// ci assicura che l'indice sia valido
	assert(i >= 0 && i < _size); 
	return _vec[i];
}


template<class R>
R Vector<R>::operator[](unsigned int i) const {
	assert(i >= 0 && i < _size);
	return _vec[i];
}


template<class R>
Vector<R>& Vector<R>::operator=(const Vector<R>& v) {
	if(this != &v){
		_cap = v._cap;
		
		if(_size != v._size)
		{
			_size = v._size;
			delete [] _vec;
			_vec = new R[_cap];
		}
		for(int i = 0; i < _size; ++i)
			_vec[i] = v._vec[i];
	}
	return *this;
}


// * implementazione metodi

template<class R>
void Vector<R>::pushBack(const R& e){
	if(_size == _cap)
		reserve(_cap*2);
	_vec[_size] = e;
	_size++;	
}


template<class R>
const R& Vector<R>::back() const {
	assert(_size > 0);
	return _vec[_size - 1];
}


template<class R>
void Vector<R>::popBack(){
	if(_size > 0);
		_size--;
}


// imposta la capacità
template<class R>
void Vector<R>::reserve(unsigned int newSize){
	if(newSize > _cap){
		_cap = newSize;
		R* tmp = new R[_cap];
		for(int i = 0; i < _size; i++){
			tmp[i] = _vec[i];
		}
		delete [] _vec;
		_vec = tmp;
	}
}


template<class R>
void Vector<R>::resize(unsigned int newSize){
	reserve(newSize);
	_size = newSize;
}


// operatori di stream input output
template<class R>
ostream& operator<<(ostream& out, const Vector<R>& v){
	out << "(";
	for(int i = 0; i < v._size; ++i){
		out << " " << v[i];
	}
	out << " )\n";
	return out;
}

// TODO AGGIUNGERE operator>>


#endif
