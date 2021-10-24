#ifndef PROGRAMMATORE_H
#define PROGRAMMATORE_H

#include <iostream>
#include <string>
using namespace std;


class Programmatore{

	friend ostream& operator<<(ostream& out, const Programmatore& p);
	friend istream& operator>>(istream& in, Programmatore& p);

private:
	string nome;
	unsigned eta;
	unsigned stipendio;
	unsigned anni_esperienza;
	bool senior;

public:
//getters
	// siccome la funzione non modifica l'oggetto su cui viene chiamata
	// posso aggiungere const
	string getNome() const { return nome; };
	unsigned getEta() const { return eta; }
	unsigned getStipendio() const { return stipendio; }
	unsigned getAnniEsperienza() const { return anni_esperienza; }
	bool isSenior() const { return senior; }

//setters
	void setNome(string nome) { (*this).nome = nome; }
	// oppure ....			  { this->nome = nome; }
	void setEta(unsigned eta) {  this->eta = eta; }
	void setStipendio(unsigned stipendio) {  this->stipendio = stipendio; }
	void setAnniEsperienza(unsigned anni_esperienza) {  this->anni_esperienza = anni_esperienza; }
	void setIsSenior(bool isSenior) { this->senior = isSenior;}
};


// non richiede lo specificatore di scope perché è una funzione esterna
ostream& operator<<(ostream& out, const Programmatore& p){
	out << "Nome: " << p.nome << endl;
	out << "Eta': " << p.eta << endl;
	out << "Stipendio: " << p.stipendio << endl;
	out << "Esperienza: " << p.anni_esperienza << endl;

	if(p.senior) out << "Senior\n";
	else out << "Junior\n";

	return out;
}


istream& operator>>(istream& in, Programmatore& p){
	cout << "inserisci nome: ";
	string nome; in >> nome; p.setNome(nome);
	
	cout << "inserisci eta: ";
	unsigned eta; in >> eta; p.setEta(eta);
	
	cout << "inserisci stipendio: ";
	unsigned stipendio; in >> stipendio; p.setStipendio(stipendio);
	
	cout << "inserisci anni di esperienza: ";
	unsigned esperienza; in >> esperienza; p.setAnniEsperienza(esperienza);
	
	cout << "inserisci senior (0|1): ";
	int senior; in >> senior; p.setIsSenior((bool)senior);

	return in;
}

#endif


