#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <assert.h>
#include "Libro.h"
#include "Cliente.h"
#include <vector>

class Biblioteca{

private:

	Libro* libri;
	unsigned sizeLibri;
	unsigned capLibri;

	Cliente* clienti;
	unsigned sizeClienti;
	unsigned capClienti;


	template<class T>
	void ridimensionaArray(T* &arr, unsigned& capacity);

	template<class T>
	void eliminaElemento(T* arr, unsigned& size, unsigned index); 


public:
	Biblioteca();
	~Biblioteca();

	void aggiungiLibro(Libro libro);
	void rimuoviLibro(int index);

	void aggiungiCliente(Cliente cliente);
	void rimuoviCliente(int index);

	Libro* cercaLibro(unsigned long ID) const;
	Libro* cercaLibro(string Nome) const;

	Cliente* cercaCliente(unsigned long ID) const;
	Cliente* cercaCliente(string codiceFiscale) const;


	void stampaLibriInPrestito() const;
	void stampaClientiCheDevonoRestituireLibro() const;

};

Biblioteca::Biblioteca(){
	capLibri = 4;
	capClienti = 4;

	sizeLibri = sizeClienti = 0;

	libri = new Libro[capLibri];
	clienti = new Cliente[capClienti];
}

Biblioteca::~Biblioteca(){
	delete [] libri;
	delete [] clienti;
}

template<class T>
void Biblioteca::ridimensionaArray(T* &arr, unsigned& capacity){

	T* tmp = new T[capacity * 2];
	
	for (int i = 0; i < capacity; i++)
		tmp[i] = arr[i];	

	delete [] arr;
	arr = tmp;
	capacity *=2; 
}

template<class T>
void Biblioteca::eliminaElemento(T* arr, unsigned& size, unsigned index){
	for(int i = index; i < size-1; i++)
		arr[i] = arr[i+1];

	size--;
}

void Biblioteca::aggiungiLibro(Libro libro){
	if(sizeLibri == capLibri)
		ridimensionaArray(libri, capLibri);

	libri[sizeLibri] = libro;
	sizeLibri++;
}

void Biblioteca::aggiungiCliente(Cliente cliente){
	if(sizeClienti == capClienti)
		ridimensionaArray(clienti, capClienti);

	clienti[sizeClienti] = cliente;
	sizeClienti++;
}

void Biblioteca::rimuoviLibro(int index){
	assert(index >= 0 && index < sizeLibri);

	eliminaElemento(libri, sizeLibri, index);
}

void Biblioteca::rimuoviCliente(int index){
	assert(index >= 0 && index < sizeClienti);

	eliminaElemento(clienti, sizeClienti, index);
}

// Libro* cercaLibro(unsigned long ID) const;
// Libro* cercaLibro(string Nome) const;

// Cliente* cercaCliente(unsigned long ID) const;
// Cliente* cercaCliente(string codiceFiscale) const;


void Biblioteca::stampaLibriInPrestito() const {
	for(int i = 0; i < sizeLibri; i++)
		if(!libri[i].isDisponibile()){
			cout << "Nome: " << libri[i].getNome() << endl; 
			cout << "Autori: " << libri[i].getAutori() << endl; 
			cout << "Casa editrice: " << libri[i].getCasaEditrice() << endl; 
			cout << "Prestato a: " << libri[i].getPrestatoA()->getNome()
				 << " " << libri[i].getPrestatoA()->getCognome() << endl;
		}
}

void Biblioteca::stampaClientiCheDevonoRestituireLibro() const {
	for(int i = 0; i < sizeLibri; i++)
		if(libri[i].isDisponibile()){
			Cliente* cliente = libri[i].getPrestatoA()
			cout << "Nome: " << cliente->getNome() << endl;
			cout << "Cognome: " << cliente->getCognome() << endl;
			cout << "Codice fiscale: " << cliente->getCodiceFiscale() << endl;

			cout << "ha preso in prestito: " << libri[i].getNome() << endl; 
		}	
}



#endif
