#ifndef LIBRO_H
#define LIBRO_H


#include <string>
#include "Cliente.h"

using namespace std;

class Libro{

	enum StatoLibro{ disponibile, inPrestito };
private:

	unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string autori;
	
	StatoLibro statoLibro;
	Cliente* prestatoA = nullptr;


public:

	Libro();
	Libro(string nome, string autori);

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }

	Libro operator=(const Libro&);

};
unsigned long Libro::IDCounter = 0;


Libro::Libro() {
	IDCounter += ((int)nome[0] + nome.size()) % 10;
	ID = IDCounter;

	this->nome = "";
	this->autori = "";

}


Libro::Libro(string nome, string autori) {
	IDCounter += ((int)nome[0] + nome.size()) % 10;
	ID = IDCounter;

	this->nome = nome;
	this->autori = autori;

}

Libro Libro::operator=(const Libro& libro){
	this->ID = libro.ID;
	this->nome = libro.nome;
	this->autori = libro.autori;
	this->statoLibro = libro.statoLibro;
	this->prestatoA = libro.prestatoA;

	return *this;
}




#endif 
