#include <iostream>
#include "Biblioteca.h"
#include "Libro.h"
#include "Cliente.h"

using namespace std;

void stampaPrompt();

void inserisciLibro();
void rimuoviLibro();
void inserisciCliente();
void rimuoviCliente();
void inserisciPrestito();
void consegnaLibro();
void stampaLibriInPrestito();
void stampaClientiConPrestito();
void stampaTuttiLibri();
void stampaTuttiClienti();


Biblioteca bib;

int main(){
	
	
	char scelta;
	bool terminaInput = false, inputValido = true;
	while(!terminaInput){
		if(inputValido)
			stampaPrompt();	
			
		inputValido = true;
			
		cin >> scelta;
		switch(scelta){
			case '0':
				inserisciLibro();
				break;
			
			case '1':
				rimuoviLibro();
				break;
			
			case '2':
				inserisciCliente();
				break;
			
			case '3':
				rimuoviCliente();
				break;
			
			case '4':
				inserisciPrestito();
				break;
			
			case '5':
				consegnaLibro();
				break;
			
			case '6':
				stampaLibriInPrestito();
				break;
			
			case '7':
				stampaClientiConPrestito();
				break;
			
			case '8':
				stampaTuttiLibri();
				break;
			
			case '9':
				stampaTuttiClienti();
				break;
				
			case '.':
				terminaInput = true;
				break;
			
			default:
				cout << endl << "Input non valido, reinserire: ";
				inputValido = false;
				break;
		}
		system("pause");
	}
			
	return 0;
}

void stampaPrompt(){
	cout << "Scegli la funzione:" << endl;
	cout << "\t0 - Inserisci un libro" << endl;
	cout << "\t1 - Rimuovi un libro" << endl;
	cout << "\t2 - Inserisci un cliente" << endl;
	cout << "\t3 - Rimuovi un cliente" << endl;
	cout << "\t4 - Inserisci un prestito" << endl;
	cout << "\t5 - Consegna un libro" << endl;
	cout << "\t6 - Stampa i libri in prestito" << endl;
	cout << "\t7 - Stampa i clienti che hanno un libro in prestito" << endl;
	cout << "\t8 - Stampa tutti i libri" << endl;
	cout << "\t9 - Stampa tutti i clienti" << endl;
	cout << "\t. - esci" << endl;
	cout << "Inserisci: ";
}

void inserisciLibro(){
	bib.aggiungiLibro();
}

void rimuoviLibro(){
	stampaTuttiLibri();
	cout << endl << "Inserisci numero libro da eliminare: ";
	unsigned cod;
	cin >> cod;
	bib.rimuoviLibro(cod);
}

void inserisciCliente(){
	bib.aggiungiCliente();
}

void rimuoviCliente(){
	stampaTuttiClienti();
	cout << endl << "Inserisci numero cliente da eliminare: ";
	unsigned cod;
	cin >> cod;
	bib.rimuoviCliente(cod);
}

void inserisciPrestito(){
	Libro *l = nullptr;
	Cliente *c = nullptr;
	unsigned codLibro;
	unsigned codCliente;
	
	bib.stampaTuttiLibri();
	
	do{
		cout << endl << "Scegli codice libro da dare in prestito: ";
		cin >> codLibro;
	
		l = bib.cercaLibro(codLibro);
	} while(l == nullptr);
	
	bib.stampaTuttiClienti();
	
	do{
		cout << endl << "Scegli codice cliente a cui dare in prestito il libro: ";
		cin >> codCliente;
	
		c = bib.cercaCliente(codCliente);
	} while(c == nullptr);
	
	bib.prestito(*l, *c);
}

void consegnaLibro(){
	Libro *l = nullptr;
	Cliente *c = nullptr;
	unsigned codLibro;
	unsigned codCliente;
	
	if(bib.stampaLibriInPrestito()){
		do{
			cout << endl << "Scegli codice libro da riconsegnare: ";
			cin >> codLibro;
	
			l = bib.cercaLibro(codLibro);
		} while(l == nullptr);
	
		c = bib.cercaCliente(l->getCodClienteAffidatario());
	
		bib.riconsegna(*l, *c);
	}
	else
		cout << "NESSUN LIBRO AFFIDATO IN PRESTITO" << endl;
}

void stampaLibriInPrestito(){
	bib.stampaLibriInPrestito();
}

void stampaClientiConPrestito(){
	bib.stampaClientiAffidatari();
}

void stampaTuttiLibri(){
	bib.stampaTuttiLibri();
}

void stampaTuttiClienti(){
	bib.stampaTuttiClienti();
}
