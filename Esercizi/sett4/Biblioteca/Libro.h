#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Cliente;

class Libro{

	enum StatoLibro{ disponibile, inPrestito };
private:

	const unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string autori;
	
	StatoLibro statoLibro;
	Cliente* prestatoA = nullptr;


public:
	Libro(string nome, string autori);

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }

};
unsigned long Libro::IDCounter = 0;

Libro::Libro(string nome, string autori): ID{IDCounter} {
	IDCounter += ((int)nome[0] + nome.size()) % 10;

	this->nome = nome;
	this->autori = autori;

}

#endif 
