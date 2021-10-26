#ifndef CLIENTE_H
#define CLIENTE_H


#include <string>
// #include "Libro.h"

using namespace std;

class Cliente{
private:
	unsigned long ID;
	static unsigned long IDCounter;
	string nome;
	string cognome;
	string codiceFiscale;

	// Libro* libroInPrestito = nullptr;
	bool deveRestituireLibro = false;
	
public:
	Cliente();
	Cliente(string nome, string cognome, string codiceFiscale);

	unsigned long getID() const { return ID; }
	string getNome() const { return nome; }
	string getCognome() const { return cognome; }
	string getCodiceFiscale() const { return codiceFiscale; }

	void setNome(string nome) { this->nome = nome; }
	void setCognome(string cognome) { this->cognome = cognome; }
	void setCodiceFiscale(string codiceFiscale) { this->codiceFiscale = codiceFiscale; }

	Cliente operator=(const Cliente&);
};
unsigned long Cliente::IDCounter = 0;

Cliente::Cliente() {	
	IDCounter += (nome.size() + cognome.size()) % 10;
	ID = IDCounter; 
	
	nome = "";
	cognome = "";
	codiceFiscale = "";
}

Cliente::Cliente(string nome, string cognome, string codiceFiscale) {
	IDCounter += (nome.size() + cognome.size()) % 10;
	ID = IDCounter; 
	
	this->nome = nome;
	this->cognome = cognome;
	this->codiceFiscale = codiceFiscale;
}

Cliente Cliente::operator=(const Cliente& cliente){
	this->ID = cliente.ID;
	this->nome = cliente.nome;
	this->cognome = cliente.cognome;
	this->codiceFiscale = cliente.codiceFiscale;

	return *this;
}


#endif
