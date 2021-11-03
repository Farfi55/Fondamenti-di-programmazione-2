#ifndef DIPENDENTE_H
#define DIPENDENTE_H

#include <iostream>
#include <string>
using namespace std;

class Dipendente {

private:
	string id;
	string nome;
	string cognome;
	float stipendio;

public:
	Dipendente() {};
	Dipendente(string id, string nome, string cognome, float stipendio);
	Dipendente(const Dipendente& dipendente);

	string getId() const { return id; }
	string getNome() const { return nome; }
	string getCognome() const { return cognome; }
	float getStipendio() const { return stipendio; }
	
	void getId(string id) { this->id = id; }
	void setNome(string nome) { this->nome = nome; }
	void setCognome(string cognome) { this->cognome = cognome; }
	void setStipendio(float stipendio) { this->stipendio = stipendio; }
	
	
	friend ostream& operator<<(ostream& o, const Dipendente& d){
		o << d.id << " " << d.nome << " " << d.cognome << " " << d.stipendio << " euro" << endl;
		return o;
	}
	
};

Dipendente::Dipendente(string id, string nome, string cognome, float stipendio):
	id{id},
	nome{nome},
	cognome{cognome},
	stipendio{stipendio}
{}

Dipendente::Dipendente(const Dipendente& dipendente):
	id{dipendente.id},
	nome{dipendente.nome},
	cognome{dipendente.cognome},
	stipendio{dipendente.stipendio}
{}


#endif
