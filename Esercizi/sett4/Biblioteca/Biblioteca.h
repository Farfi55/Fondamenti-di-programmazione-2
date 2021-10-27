#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <assert.h>
#include "Libro.h"
#include "Cliente.h"
#include <vector>
#include <iostream>

using namespace std;

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

	bool prestito(Libro* libro, Cliente* cliente);
	bool riconsegna(Libro* libro, Cliente* cliente);


	void stampaLibri() const;
	void stampaClienti() const;

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

Libro* Biblioteca::cercaLibro(unsigned long ID) const {
	for(int i = 0; i < sizeLibri; i++)
		if(libri[i].getID() == ID)
			return &libri[i];
	
	return nullptr;
}


Libro* Biblioteca::cercaLibro(string Nome) const {
	for(int i = 0; i < sizeLibri; i++)
		if(libri[i].getNome() == Nome)
			return &libri[i];

	return nullptr;
}

Cliente* Biblioteca::cercaCliente(unsigned long ID) const {
	for(int i = 0; i < sizeClienti; i++)
		if(clienti[i].getID() == ID)
			return &clienti[i];

	return nullptr;
}

Cliente* Biblioteca::cercaCliente(string codiceFiscale) const {
	for(int i = 0; i < sizeClienti; i++)
		if(clienti[i].getCodiceFiscale() == codiceFiscale)
			return &clienti[i];

	return nullptr;
}

bool Biblioteca::prestito(Libro* libro, Cliente* cliente){
	return libro->presta(cliente);
}

bool Biblioteca::riconsegna(Libro* libro, Cliente* cliente){
	return libro->riconsegna(cliente);
}

void Biblioteca::stampaLibri() const {
	for(int i = 0; i < sizeLibri; i++){
		cout << "ID: " << libri[i].getID() << endl; 
		cout << "Nome: " << libri[i].getNome() << endl; 
		cout << "Autori: " << libri[i].getAutori() << endl; 
		cout << "Casa editrice: " << libri[i].getCasaEditrice() << endl << endl; 
	}
}


void Biblioteca::stampaClienti() const {
	for(int i = 0; i < sizeClienti; i++){
		cout << "ID: " << clienti[i].getID() << endl;
		cout << "Nome: " << clienti[i].getNome() << endl;
		cout << "Cognome: " << clienti[i].getCognome() << endl;
		cout << "Codice fiscale: " << clienti[i].getCodiceFiscale() << endl << endl;
	}
}

void Biblioteca::stampaLibriInPrestito() const {
	for(int i = 0; i < sizeLibri; i++)
		if(!libri[i].isDisponibile()){
			cout << "Nome: " << libri[i].getNome() << endl; 
			cout << "Autori: " << libri[i].getAutori() << endl; 
			cout << "Casa editrice: " << libri[i].getCasaEditrice() << endl; 
			cout << "Prestato a: " << libri[i].getPrestatoA()->getNome()
				 << " " << libri[i].getPrestatoA()->getCognome() << endl << endl;
		}
}

void Biblioteca::stampaClientiCheDevonoRestituireLibro() const {
	for(int i = 0; i < sizeLibri; i++)
		if(!libri[i].isDisponibile()){
			Cliente* cliente = libri[i].getPrestatoA();
			cout << "Nome: " << cliente->getNome() << endl;
			cout << "Cognome: " << cliente->getCognome() << endl;
			cout << "Codice fiscale: " << cliente->getCodiceFiscale() << endl;

			cout << "ha preso in prestito: " << libri[i].getNome() << endl << endl; 
		}	
}



#endif
