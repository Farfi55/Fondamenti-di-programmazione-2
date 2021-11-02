#ifndef STUDENTE_H
#define STUDENTE_H
#include <iostream>
#include <string>

using namespace std;

class Studente{

friend ostream& operator<< (ostream& out, const Studente& stud);
friend istream& operator>> (istream& in, Studente& stud);

private:
	string matricola;
	unsigned eta;
	unsigned esami_sostenuti;
	string nomi_esami[24];
	unsigned voti_esami[24];
	unsigned cfu_esami[24];

public:

	Studente();
	Studente(string matricola, unsigned eta);
	void aggiungiEsame(string esame, unsigned voto, unsigned cfu);
	void rimuoviUltimoEsame();
	float getMediaVoti() const;
	float getMediaPonderata() const;
	unsigned getVotoPiuBasso() const;
	unsigned getVotoPiuAlto() const;
	unsigned getVotoI(unsigned i) const;

// Getters
	string getMatricola() const { return matricola; }
	unsigned getEta() const { return eta; }
	unsigned getEsamiSostenuti() const { return esami_sostenuti; }

// Setters
	void setMatricola(string matricola) { this->matricola = matricola; }
	void setEta(unsigned eta) { this->eta = eta; }
	// void setEsamiSostenuti( unsigned esami_sostenuti) { this->esami_sostenuti = esami_sostenuti; }

};

#endif
