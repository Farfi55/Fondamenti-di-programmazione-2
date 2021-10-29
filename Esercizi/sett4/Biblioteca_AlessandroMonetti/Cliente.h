#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
using namespace std;

class Cliente{
	//Funzioni di I/O
	//friend istream& operator >>(istream& in, Cliente &c);
	friend ostream& operator <<(ostream& out, const Cliente &c);
	
	private:
		unsigned codCliente;
		unsigned codLibroInPrestito;
		string nome;
		string cognome;
		string codFiscale;
		
	public:
		static unsigned ultimoCodiceCliente;
		//Getters
		unsigned getCodCliente() const {return codCliente;}
		unsigned getCodLibroInPrestito() const {return codLibroInPrestito;}
		string getNome() const {return nome;}
		string getCognome() const {return cognome;}
		string getCodiceFiscale() const {return codFiscale;}
		
		//Setters
		void setNome(string nome) {this -> nome = nome;}
		void setCognome(string cognome) {this -> cognome = cognome;}
		void setCodiceFiscale(string codFiscale) {this -> codFiscale = codFiscale;}
		void setCodLibroInPrestito(unsigned codLibroInPrestito) {this -> codLibroInPrestito = codLibroInPrestito;}
		
		//Costruttore
		Cliente() : nome(""), cognome(""), codFiscale(""), codCliente(ultimoCodiceCliente++), codLibroInPrestito(0) {}
		Cliente(string nome, string cognome, string codFiscale);
		 
};

unsigned Cliente::ultimoCodiceCliente = 1;

ostream& operator <<(ostream& out, const Cliente &c){
	out << endl << "------------------------";
	out << endl << "Cliente num. " << c.codCliente << endl;
	out << "Nome:\t\t\t" << c.nome << endl;
	out << "Cognome:\t\t" << c.cognome << endl;
	out << "Codice Fiscale:\t\t" << c.codFiscale << endl;
	out << "Libro in prestito:\t";
	if(c.codLibroInPrestito == 0)
		out << "NO" << endl;
	else
		out << "SI" << endl;
	
	return out;
}

Cliente::Cliente(string nome, string cognome, string codFiscale){
	this -> nome = nome;
	this -> cognome = cognome;
	this -> codFiscale = codFiscale;
	codLibroInPrestito = 0;				//codiceLibroInPrestito == 0 -> nessun libro in prestito
	codCliente = ultimoCodiceCliente++;
}

#endif

