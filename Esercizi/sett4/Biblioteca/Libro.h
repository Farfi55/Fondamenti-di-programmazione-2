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


	Libro operator=(const Libro&);
};
unsigned long Libro::IDCounter = 0;


Libro::Libro() {
	IDCounter += ((int)nome[0] + nome.size()) % 10;
	ID = IDCounter;

	this->nome = "";
	this->autori = "";
	this->casaEditrice = "";

}


Libro::Libro(string nome, string autori, string casaEditrice) {
	IDCounter += ((int)nome[0] + nome.size()) % 10;
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


#endif 
