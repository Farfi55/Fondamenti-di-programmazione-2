#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

//Librerie pre-esistenti
#include <iostream>
#include <vector>
#include <iterator>
#include <cstddef>		//Per l'utilizzo di nullptr
//Classi autoprodotte
#include "Libro.h"
#include "Cliente.h"

using namespace std;

class Biblioteca{
	private:
		vector<Libro> libri;
		vector<Cliente> clienti;
		
	public:
		//Getters
		Libro getLibroPos(unsigned i) const {return libri.at(i);}
		Cliente getClientePos(unsigned i) const {return clienti.at(i);}
		
		
		//Costruttore
		Biblioteca(){};	
		
		
	//Metodi
		void aggiungiLibro();
		void rimuoviLibro(unsigned codLibro);
		Libro *cercaLibro(unsigned codLibro);
		Libro *cercaLibro(string titolo);
		void liberaLibro(unsigned codLibro);
	
		void aggiungiCliente();
		void rimuoviCliente(unsigned codCliente);
		Cliente *cercaCliente(unsigned codCliente);
		Cliente *cercaCliente(string codFiscale);
		void liberaCliente(unsigned codClienteAffidatario);
	
		void prestito(Libro &l, Cliente &c);
		void riconsegna(Libro &l, Cliente &c);
	
		void stampaTuttiLibri();
		bool stampaLibriInPrestito();
		void stampaTuttiClienti();
		bool stampaClientiAffidatari();
};

Libro* Biblioteca::cercaLibro(unsigned codLibro){
	for(auto i = libri.begin(); i != libri.end(); ++i)
		if((*i).getCodLibro() == codLibro)
			return &(*i);
	
	return nullptr;
}

Libro *Biblioteca::cercaLibro(string titolo){
	for(auto i = libri.begin(); i != libri.end(); ++i)
		if((*i).getTitolo() == titolo)
			return &(*i);
	
	return nullptr;
}

Cliente *Biblioteca::cercaCliente(unsigned codCliente){
	for(auto i = clienti.begin(); i != clienti.end(); ++i)
		if((*i).getCodCliente() == codCliente)
			return &(*i);
	
	return nullptr;
}

Cliente *Biblioteca::cercaCliente(string codFiscale){
	for(auto i = clienti.begin(); i != clienti.end(); ++i)
		if((*i).getCodiceFiscale() == codFiscale)
			return &(*i);
			
	return nullptr;
}

void Biblioteca::aggiungiLibro(){
	string titolo = "", casaEditrice = "", autore = "";
	vector<string> autori;
	
	cin.ignore();
	
	cout << endl << "Inserisci il titolo del libro: ";
	getline(cin, titolo);
	
	cout << "Inserisci la casa editrice: ";
	getline(cin, casaEditrice);
	
	cout << "Inserisci uno per volta gli autori (termina con '.'):" << endl;
	unsigned cont = 1;
	bool inputValido = true;
	
	while(inputValido){
		cout << "Autore " << cont++ << ": ";
		getline(cin, autore);
		if(autore != ".")
			autori.push_back(autore);
		else
			inputValido = false;
			
		autore = "";
	}
	
	libri.push_back(*new Libro(titolo, autori, casaEditrice));
	cout << endl << "Libro aggiunto correttamente" << endl << endl;
}

void Biblioteca::rimuoviLibro(unsigned codLibro){
	int posLibro = -1;
	
	for(auto i = libri.begin(); i != libri.end(); ++i)
		if(codLibro == (*i).getCodLibro())
			posLibro = i - libri.begin();
	
	if(posLibro != -1){
		unsigned codClienteAffidatario = libri.at(posLibro).getCodClienteAffidatario();
		
		if(codClienteAffidatario != 0)
			liberaCliente(codClienteAffidatario);
		
		libri.erase(libri.begin()+posLibro);	
		cout << endl << "Libro numero " << codLibro << " eliminato correttamente" << endl << endl;	
	}		
	else
		cout << endl <<  "Il codice inserito non corrisponde ad alcun libro in biblioteca" << endl << endl;
}

void Biblioteca::liberaCliente(unsigned codClienteAffidatario){
	for(auto i = clienti.begin(); i != clienti.end(); ++i)
		if((*i).getCodCliente() == codClienteAffidatario)
			(*i).setCodLibroInPrestito(0);
}

void Biblioteca::aggiungiCliente(){
	string nome = "", cognome = "", codiceFiscale = "";
	
	cin.ignore();
	
	cout << endl << "Inserisci nome: ";
	getline(cin, nome);
	
	cout << "Inserisci cognome: ";
	getline(cin, cognome);
	
	cout << "Inserisci codice fiscale:" << endl;
	getline(cin, codiceFiscale);
	
	clienti.push_back(*new Cliente(nome, cognome, codiceFiscale));
	cout << endl << "Cliente aggiunto correttamente" << endl << endl;
}

void Biblioteca::rimuoviCliente(unsigned codCliente){
	int posCliente = -1;
	
	for(auto i = clienti.begin(); i != clienti.end(); ++i)
		if(codCliente == (*i).getCodCliente())
			posCliente = i - clienti.begin();
	
	if(posCliente != -1){
		unsigned codLibroInPrestito = clienti.at(posCliente).getCodLibroInPrestito();
		
		if(codLibroInPrestito != 0)
			liberaLibro(codLibroInPrestito);
		
		clienti.erase(clienti.begin()+posCliente);	
		cout << endl << "Cliente numero " << codCliente << " eliminato correttamente" << endl << endl;	
	}		
	else
		cout << endl <<  "Il codice inserito non corrisponde ad alcun libro in biblioteca" << endl << endl;
}

void Biblioteca::liberaLibro(unsigned codLibro){
	for(auto i = libri.begin(); i != libri.end(); ++i)
		if((*i).getCodLibro() == codLibro)
			(*i).setCodClienteAffidatario(0);
}

void Biblioteca::prestito(Libro &l, Cliente &c){
	if(l.getCodClienteAffidatario() == 0)
		if(c.getCodLibroInPrestito() == 0){
			l.setCodClienteAffidatario(c.getCodCliente());
			c.setCodLibroInPrestito(l.getCodLibro());
			
			cout << "Prestito effettuato" << endl;
		}		
		else
			cout << "Prestito non effettuato, il libro " << l.getCodLibro() << " e' gia' in prestito" << endl;	
	else
		cout << "Prestito non effettuato, il cliente " << c.getNome() << " " << c.getCognome() << " ha gia' un libro in prestito" << endl;
}

void Biblioteca::riconsegna(Libro &l, Cliente &c){
	if(l.getCodClienteAffidatario() != 0)
		if(c.getCodLibroInPrestito() != 0){
			l.setCodClienteAffidatario(0);
			c.setCodLibroInPrestito(0);
			
			cout << "Riconsegna effettuata" << endl;
		}		
		else
			cout << "Riconsegna non effettuata, il libro " << l.getCodLibro() << " non e' in prestito" << endl;	
	else
		cout << "Prestito non effettuato, il cliente \"" << c.getNome() << " " << c.getCognome() << "\" non ha un libro in prestito" << endl;		
}

bool Biblioteca::stampaLibriInPrestito(){
	if(libri.begin() == libri.end()){
		cout << endl << "NESSUN LIBRO AFFIDATO IN PRESTITO" << endl << endl;
		return false;
	}
	else
		for(auto i = libri.begin(); i != libri.end(); ++i){	
			unsigned codClienteAffidatario = (*i).getCodClienteAffidatario();
			if(codClienteAffidatario != 0){	//Se libro in prestito			
				cout << *i;
			
				int posClienteAffidatario = -1;
			
				for(auto i = clienti.begin(); i != clienti.end(); ++i)
					if(codClienteAffidatario == (*i).getCodCliente())
						posClienteAffidatario = i - clienti.begin();
			
				cout << "Cliente affidatario:\t\t" << clienti.at(posClienteAffidatario).getNome() << " " << clienti.at(posClienteAffidatario).getCognome();			
				cout << endl << endl; 
			}
		}
	
	return true;
}

bool Biblioteca::stampaClientiAffidatari(){
	if(clienti.begin() == clienti.end()){
		cout << endl << "NESSUN CLIENTE CON LIBRI IN PRESTITO" << endl << endl;
		return false;
	}	
	else
		for(auto i = clienti.begin(); i != clienti.end(); ++i){
			unsigned codLibroInPrestito = (*i).getCodLibroInPrestito();
			if((*i).getCodLibroInPrestito() != 0){	//Se cliente ha un libro in prestito			
				cout << (*i);

				int posLibroInPrestito = -1;
			
				for(auto i = libri.begin(); i != libri.end(); ++i)
					if(codLibroInPrestito == (*i).getCodLibro())
						posLibroInPrestito = i - libri.begin();
					
				cout << "Titolo libro in prestito: " << libri.at(posLibroInPrestito).getTitolo();
			
				cout << endl << endl; 
			}
		}
		
	return true;
}

void Biblioteca::stampaTuttiLibri(){
	if(libri.begin() == libri.end())
		cout << endl << "NESSUN LIBRO PRESENTE NEL DATABASE" << endl << endl;
	else
		for(auto i = libri.begin(); i != libri.end(); ++i)
			cout << (*i) << endl;	
}

void Biblioteca::stampaTuttiClienti(){
	if(clienti.begin() == clienti.end())
		cout << endl << "NESSUN CLIENTE PRESENTE NEL DATABASE" << endl << endl;
	else
		for(auto i = clienti.begin(); i != clienti.end(); ++i)
			cout << (*i) << endl;	
}
#endif
