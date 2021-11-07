#include <iostream>
#include <string>
#include "Biblioteca.h"
#include "Libro.h"
#include "Cliente.h"

using namespace std;

void inserisciLibro(Biblioteca* biblioteca);
void rimuoviLibro(Biblioteca* biblioteca);

void inserisciCliente(Biblioteca* biblioteca);
void rimuoviCliente(Biblioteca* biblioteca);

void effettuaPrestitoORiconsegna(Biblioteca* biblioteca, bool effettuaPrestito);


void stampaSceltaFunzione() {
	cout << "Scegli la funzione:\n"
		<< " 0 - esci\n"
		<< " 1 - Inserisci un libro\n"
		<< " 2 - Rimuovi un libro\n"
		<< " 3 - Inserisci un cliente\n"
		<< " 4 - Rimuovi un cliente\n"
		<< " 5 - Inserisci un prestito\n"
		<< " 6 - Consegna un libro\n"
		<< " 7 - Stampa tutti i libri\n"
		<< " 8 - Stampa tutti i clienti\n"
		<< " 9 - Stampa i libri in prestito\n"
		<< "10 - Stampa i clienti che hanno un libro in prestito\n"
		// << "11 - Salva i dati su File\n"
		// << "12 - Carica i dati da File\n"
		<< "Inserisci: ";
}

int main() {

	Biblioteca biblioteca = Biblioteca();

	biblioteca.aggiungiLibro(Libro("1984", "George Orwell", "Asbro")); // 0
	biblioteca.aggiungiLibro(Libro("Alice nel paese delle meraviglie",
		"Robert Wild, Daniel Winston", "Mondadori")); // 1
	biblioteca.aggiungiLibro(Libro("c++ Primer 5th edition",
		"Stanley B. Lippman, Josée Lajoie, Barbara E. Moo", "Addison-Wesley")); // 2
	biblioteca.aggiungiLibro(Libro("La Divina Commedia", "Dante Alighieri", "il Monaco emanuense (c)")); // 3
	biblioteca.aggiungiLibro(Libro("I 3 porcellini", "M. Duca, P. Tudda, F. Gallo", "Mondadori")); // 4
	biblioteca.aggiungiLibro(Libro("Le Tigri della siberia", "Taigah", "ND")); // 5
	biblioteca.aggiungiLibro(Libro("Il piccolo principe", "ND", "ND")); // 6
	biblioteca.aggiungiLibro(Libro("La bella e la bestia", "ND", "ND")); // 7


	biblioteca.aggiungiCliente(Cliente("Raimondo", "Rossi", "RSIRAI")); // 0
	biblioteca.aggiungiCliente(Cliente("Zaniela", "Verdi", "VRDNEL")); // 1
	biblioteca.aggiungiCliente(Cliente("John", "Blues", "BLUJON")); // 2
	biblioteca.aggiungiCliente(Cliente("Timmy", "Tisca'", "TSCTMM")); // 3
	biblioteca.aggiungiCliente(Cliente("Letizia", "Tusca", "TSCLTZ")); // 4
	biblioteca.aggiungiCliente(Cliente("Tiziana", "Topolino", "TOPTIZ")); // 5
	biblioteca.aggiungiCliente(Cliente("Tizio", "Tizii", "TZITZO")); // 6

	biblioteca.prestito(&biblioteca.libroA(6), &biblioteca.clienteA(3));
	biblioteca.prestito(&biblioteca.libroA(2), &biblioteca.clienteA(1));
	biblioteca.prestito(&biblioteca.libroA(1), &biblioteca.clienteA(6));
	// questi sono per testare un pò il programma, 
	// potete andare ad aggiungere tutto quanto dal programma

	// TODO aggiungere sistema di read write su file 


	bool quitting = false;
	while(!quitting) {
		stampaSceltaFunzione();

		int funzione;
		cin >> funzione;


		if(funzione == 0) // QUIT			
			quitting = true;

		else if(funzione == 1) // AGGIUNGI LIBRO
			inserisciLibro(&biblioteca);

		else if(funzione == 2) // RIMUOVI LIBRO
			rimuoviLibro(&biblioteca);

		else if(funzione == 3) // AGGIUNGI CLIENTE
			inserisciCliente(&biblioteca);

		else if(funzione == 4) //RIMUOVI CLIENTE
			rimuoviCliente(&biblioteca);

		else if(funzione == 5) // FUNZIONE PRESTITO
			effettuaPrestitoORiconsegna(&biblioteca, true);

		else if(funzione == 6) // FUNZIONE RICONSEGNA
			effettuaPrestitoORiconsegna(&biblioteca, false);

		else if(funzione == 7) // STAMPA TUTTI I LIBRI
			biblioteca.stampaLibri();

		else if(funzione == 8) // STAMPA TUTTI I CLIENTI
			biblioteca.stampaClienti();

		else if(funzione == 9) // STAMPA TUTTI I LIBRI PRESI IN PRESTITO
			biblioteca.stampaLibriInPrestito();

		else if(funzione == 10) // STAMPA TUTTI I CLIENTI CHE DEVONO RESTITUIRE IL LIBRO
			biblioteca.stampaClientiCheDevonoRestituireLibro();

		else
			cout << "Codice funzione non riconosciuto\n";



	}
}


// int IDcliente, IDlibro;
// cin >> IDcliente >> IDlibro;

// if(IDcliente == -1) {
// 	quitting = true; 
// 	break; 
// }

// Cliente* cliente = biblioteca.cercaCliente(IDcliente);
// if(cliente == nullptr) {
// 	cout << "NON E' STATO POSSIBILE TROVARE IL CLIENTE!\n";
// 	continue;
// }


// Libro* libro = biblioteca.cercaLibro(IDlibro);
// if(libro == nullptr) {
// 	cout << "NON E' STATO POSSIBILE TROVARE IL LIBRO!\n";
// 	continue;
// }

// if(biblioteca.prestito(libro, cliente))
// 	cout << "prestito andato a buon fine\n";
// else 
// 	cout << "non è stato possibile concludere il prestito\n";


// // biblioteca.stampaLibriInPrestito();
// biblioteca.stampaClientiCheDevonoRestituireLibro();

// }


// cout << cliente->getNome() << " " << cliente->getCognome() << endl;

// cout << endl << endl;
// biblioteca.stampaLibriInPrestito();
// cout << endl << endl;
// biblioteca.rimuoviLibro(0);


// biblioteca.stampaLibriInPrestito();
// }

void inserisciLibro(Biblioteca* biblioteca) {
	string nome, autori, casaEditrice;
	cout << "Inserisci dati libro:\n";
	cout << "nome: "; cin >> nome;
	cout << "autori (separati con ', '): "; cin >> autori;
	cout << "casa editrice: "; cin >> casaEditrice;
	biblioteca->aggiungiLibro(Libro(nome, autori, casaEditrice));
}

void rimuoviLibro(Biblioteca* biblioteca) {
	cout << "Elimina per (0: indice, 1: ID, 2: Nome): ";
	int eliminaPer; cin >> eliminaPer;

	if(eliminaPer == 0) { // indice
		int index; cin >> index;
		biblioteca->rimuoviLibro(index);
	}
	else if(eliminaPer == 1) { // ID
		int ID; cin >> ID;
		int index = biblioteca->indiceDiLibro(ID);
		if(index != -1) biblioteca->rimuoviLibro(index);
		else cout << "Non e' stato possibile trovare il libro\n";
	}
	else if(eliminaPer == 2) { // nome
		string nome; cin >> nome;
		int index = biblioteca->indiceDiLibro(nome);
		if(index != -1) biblioteca->rimuoviLibro(index);
		else cout << "Non e' stato possibile trovare il libro\n";
	}
	else cout << "Tipo di operazione non riconosciuta\n";
}

void inserisciCliente(Biblioteca* biblioteca) {
	string nome, cognome, codiceFiscale;
	cout << "Inserisci dati Cliente:\n";
	cout << "nome: "; cin >> nome;
	cout << "cognome: "; cin >> cognome;
	cout << "codice fiscale: "; cin >> codiceFiscale;
	biblioteca->aggiungiCliente(Cliente(nome, cognome, codiceFiscale));
}

void rimuoviCliente(Biblioteca* biblioteca) {
	cout << "Elimina per (0: indice, 1: ID, 2: Codice Fiscale): ";
	int eliminaPer; cin >> eliminaPer;
	if(eliminaPer == 0) { // indice
		int index; cin >> index;
		biblioteca->rimuoviCliente(index);
	}
	else if(eliminaPer == 1) { // ID
		int ID; cin >> ID;
		int index = biblioteca->indiceDiCliente(ID);
		if(index != -1) biblioteca->rimuoviCliente(index);
		else cout << "Non e' stato possibile trovare il cliente\n";
	}
	else if(eliminaPer == 2) { // Codice Fiscale
		string codiceFiscale; cin >> codiceFiscale;
		int index = biblioteca->indiceDiCliente(codiceFiscale);
		if(index != -1) biblioteca->rimuoviCliente(index);
		else cout << "Non e' stato possibile trovare il cliente\n";
	}
	else cout << "Tipo di operazione non riconosciuta\n";
}


void effettuaPrestitoORiconsegna(Biblioteca* biblioteca, bool effettuaPrestito) {
	cout << "Seleziona per (0: (ID, ID), 1: (Nome, Codice Fiscale)): ";
	int selezionaPer; cin >> selezionaPer;

	if(selezionaPer != 0 && selezionaPer != 1)
		return;

	Cliente* cliente;
	Libro* libro;
	if(selezionaPer == 0) { // per ID
		int IDlibro, IDcliente;
		cout << "Inserisci ID libro, poi ID cliente: ";
		cin >> IDlibro >> IDcliente;

		libro = biblioteca->cercaLibro(IDlibro);
		cliente = biblioteca->cercaCliente(IDcliente);
	}
	else {
		string nomeLibro, codiceFiscaleCliente;
		cout << "Inserisci nome libro, poi codice fiscale cliente: ";
		cin >> nomeLibro >> codiceFiscaleCliente;

		libro = biblioteca->cercaLibro(nomeLibro);
		cliente = biblioteca->cercaCliente(codiceFiscaleCliente);
	}

	if(cliente == nullptr) {
		cout << "NON E' STATO POSSIBILE TROVARE IL CLIENTE!\n";
		return;
	}
	else if(libro == nullptr) {
		cout << "NON E' STATO POSSIBILE TROVARE IL LIBRO!\n";
		return;
	}
	else {
		if(effettuaPrestito) { // Funzione prestito
			if(biblioteca->prestito(libro, cliente))
				cout << "prestito andato a buon fine\n";
			else
				cout << "non è stato possibile concludere il prestito\n";
		}
		else { // Funzione riconsegna
			if(biblioteca->riconsegna(libro, cliente))
				cout << "riconsegna andata a buon fine\n";
			else
				cout << "non è stato possibile concludere la riconsegna\n";
		}
	}



}



