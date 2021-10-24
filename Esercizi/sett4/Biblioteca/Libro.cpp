#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <string>
#include "Cliente.h"
using namespace std;

class Libro{

	enum StatoLibro{ disponibile, inPrestito };
private:

	const unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string[] autori;
	
	StatoLibro statoLibro;
	Cliente* prestatoA = nullptr;


public:
	Libro();

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }

};
Libro::IDCounter = 0;


Libro::Libro(string nome){
	ID = IDCounter;
	IDCounter += ((int)nome[0] + nome.size() % 10);


}



#endif 
