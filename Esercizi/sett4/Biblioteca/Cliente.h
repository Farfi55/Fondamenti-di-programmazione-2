#ifndef CLIENTE_H
#define CLIENTE_H


#include <string>
#include "Libro.h"
using namespace std;

class Cliente{
private:
	const unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string cognome;
	string codiceFiscale;

	Libro* libroInPrestito = nullptr;
	
public:

	Cliente(string nome, string cognome, string codiceFiscale);

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }
	string getCognome() const { return cognome; }
	string getCodiceFiscale() const { return codiceFiscale; }

};
unsigned long Cliente::IDCounter = 0;

Cliente::Cliente(string nome, string cognome, string codiceFiscale): ID{IDCounter} {
	
	IDCounter += (nome.size() + cognome.size()) % 10;
	this->nome = nome;
	this->cognome = cognome;
	this->codiceFiscale = codiceFiscale;
}

#endif
