#ifndef LIBRO_H
#define LIBRO_H

#include <string>
#include "Cliente.h"

using namespace std;

class Libro{

	// enum StatoLibro{ disponibile, inPrestito };

private:

	unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string autori;
	string casaEditrice;
	
	// StatoLibro statoLibro = Statolibro.disponibile;
	bool disponibile = true;

	Cliente* prestatoA = nullptr;




public:

	Libro();
	Libro(string nome, string autori, string casaEditrice);

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }
	string getAutori() const { return autori;}
	string getCasaEditrice() const { return casaEditrice;}
	bool isDisponibile() const { return disponibile; }
	Cliente* getPrestatoA() const { return prestatoA; }

	bool presta(Cliente* cliente);
	bool riconsegna(Cliente* cliente);

	Libro operator=(const Libro&);
};
unsigned long Libro::IDCounter = 0;


Libro::Libro() {
	IDCounter += 1 + ((int)nome[0] + nome.size()) % 20;
	ID = IDCounter;

	this->nome = "ND";
	this->autori = "ND";
	this->casaEditrice = "ND";

}


Libro::Libro(string nome, string autori, string casaEditrice) {
	IDCounter += 1 + ((int)nome[0] + nome.size()) % 20;
	ID = IDCounter;

	this->nome = nome;
	this->autori = autori;
	this->casaEditrice = casaEditrice;

}

Libro Libro::operator=(const Libro& libro){
	this->ID = libro.ID;
	this->nome = libro.nome;
	this->autori = libro.autori;
	this->casaEditrice = libro.casaEditrice;

	this->disponibile = libro.disponibile;
	this->prestatoA = libro.prestatoA;

	return *this;
}

bool Libro::presta(Cliente* cliente){
	if(disponibile && !cliente->deveRestituireLibro()){
		disponibile = false;
		prestatoA = cliente;
		cliente->setDeveRestituireLibro(true);
		return true;
	}
	else return false;
}
	
	
bool Libro::riconsegna(Cliente* cliente){
	if(!disponibile && cliente->deveRestituireLibro() && prestatoA == cliente){
		disponibile = true;
		prestatoA = nullptr;
		cliente->setDeveRestituireLibro(false);
		return true;
	}
	else return false;
}



#endif 
