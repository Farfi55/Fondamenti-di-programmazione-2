#ifndef LIBRO_H
#define LIBRO_H

#include <iostream>
#include <vector>
using namespace std;

class Libro{
	//Funzioni di I/O
	friend istream& operator >>(istream& in, Libro &l);
	friend ostream& operator <<(ostream& out, const Libro &l);
	
	private:
		unsigned codLibro;
		unsigned codClienteAffidatario;		//Se codClienteAffidatario == 0, il libro e' disponibile per il prestito
		string titolo;
		vector<string> autori;
		string casaEditrice;
		
	public:
		static unsigned ultimoCodLibro;
		
		//Getters
		unsigned getCodLibro() const {return codLibro;}
		unsigned getCodClienteAffidatario() const {return codClienteAffidatario;}
		string getTitolo() const {return titolo;}
		string getAutorePos(unsigned i) const {return autori.at(i);}
		string getCasaEditrice() const {return casaEditrice;}
		
		
		//Setters
		void setTitolo(string titolo) {this -> titolo = titolo;}
		void setCasaEditrice(string casaEditrice) {this -> casaEditrice = casaEditrice;}
		void setCodClienteAffidatario(unsigned codClienteAffidatario) {this -> codClienteAffidatario = codClienteAffidatario;}

				
		//Costruttori
		Libro();
		Libro(string titolo, const vector<string> autori, string casaEditrice);
};

unsigned Libro::ultimoCodLibro = 1;

Libro::Libro(){
	titolo = "";
	casaEditrice = "";
	codClienteAffidatario = 0;
}

Libro::Libro(string titolo, const vector<string> autori, string casaEditrice){
	this -> titolo = titolo;
	this -> casaEditrice = casaEditrice;
	
	//usando l'operatore '=' su oggetti di classe vector viene effettuata la copia, a differenza degli array
	this -> autori = autori;
	codLibro = ultimoCodLibro++;
	
	codClienteAffidatario = 0;
}

istream& operator >>(istream &in, Libro &l){
	//DA IMPLEMENTARE
}

ostream& operator <<(ostream &out, const Libro &l){
	out << endl << "------------------------";
	out << endl << "Libro num. " << l.codLibro << "" << endl;
	out << "Titolo:\t\t\t\t" << l.titolo << endl;
	out << "Casa editrice:\t\t\t" << l.casaEditrice << endl;
	
	out << "Autori:\t\t\t\t";
	for(auto i = l.autori.begin(); i != l.autori.end(); ++i)
		if(i != l.autori.begin())
			cout << ", " << (*i);
		else
			cout << (*i);
	
	out << endl << "Disponibile per il prestito:\t";
	if(l.codClienteAffidatario != 0)
		out << "NO" << endl;
	else
		out << "SI" << endl;
	
	return out;
}

#endif
