#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include "Libro.cpp"
#include "Cliente.cpp"
using namespace std;


class Biblioteca{


private:
	Libro* libri;
	unsigned nLibri;

	Cliente* clienti;
	unsigned nClienti;


	template<class T>
	void ridimensionaArray(T* &arr, unsigned& size);

	template<class T>
	void eliminaElemento(T* arr, unsigned size, unsigned index); 


public:
	Biblioteca();

	void aggiungiLibro()
	void RimuoviLibro()

	void aggiungiCliente()
	void RimuoviCliente()

	Libro* cercaLibro(unsigned long ID);
	Libro* cercaLibro(string Nome);
}

Biblioteca()


// template<class T>
// class LinkedList{
// public: 

// 	T item;
// 	T* next;
// 	T* previus;
// }
#endif
