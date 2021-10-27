#include <iostream>
#include <string>
#include "Biblioteca.h"
#include "Libro.h"
#include "Cliente.h"

using namespace std;

int main() {

	Biblioteca biblioteca = Biblioteca();

	biblioteca.aggiungiLibro(Libro("Alice nel paese delle meraviglie",
		"Robert Wild, Daniel Winston", "Mondadori"));
	biblioteca.aggiungiLibro(Libro("1984", "George Orwell", "Asbro"));

	biblioteca.aggiungiCliente(Cliente("Alessio", "Farfaglia", "FRLFLSS"));
	biblioteca.aggiungiCliente(Cliente("Roberto", "Rossi", "RSSROB"));
	biblioteca.aggiungiCliente(Cliente("Zaniela", "Verdi", "VRDNEL"));


	cout << "_____________________________________\n" 
		<< "CLIENTI: ";
	biblioteca.stampaClienti();
	
	cout << "\n_____________________________________\n" 
		<< "LIBRI: ";
	biblioteca.stampaLibri();
	
	


	
		
/**
 cout << "Scegli la funzione:\n"
			<< " 0 – esci\n"
			<< " 1 – Inserisci un libro\n"
			<< " 2 – Rimuovi un libro\n"
			<< " 3 – Inserisci un cliente\n"
			<< " 4 – Rimuovi un cliente\n"
			<< " 5 – Inserisci un prestito\n"
			<< " 6 – Consegna un libro\n"
			<< " 7 – Stampa tutti i libri\n"
			<< " 8 – Stampa tutti i clienti\n"
			<< " 9 – Stampa i libri in prestito\n"
			<< "10 – Stampa i clienti che hanno un libro in prestito\n"
			<< "Inserisci: "


		int funzione;
		cin >> funzione;


		inserisciPrestito(Biblioteca* biblioteca)


		switch(funzione){
			case 0:
				quitting = true;
				break;
			case 1:
				inserisciLibro(&biblioteca);
				break;
			case 2:
				rimuoviLibro(&biblioteca);
				break;
			case 3:
				inserisciCliente(&biblioteca);
				break;
			case 4:
				rimuoviCliente(&biblioteca);
				break;
			case 5:
				inserisciPrestito(biblioteca)
				break;


			default:
				cout << "Codice funzione non riconosciuto\n";
				break;
		}
*/
	bool quitting = false;
	while(!quitting){

		int IDcliente, IDlibro;
		cin >> IDcliente >> IDlibro;

		if(IDcliente == -1) {
			quitting = true; 
			break; 
		}

		Cliente* cliente = biblioteca.cercaCliente(IDcliente);
		if(cliente == nullptr) {
			cout << "NON E' STATO POSSIBILE TROVARE IL CLIENTE!\n";
			continue;
		}


		Libro* libro = biblioteca.cercaLibro(IDlibro);
		if(libro == nullptr) {
			cout << "NON E' STATO POSSIBILE TROVARE IL LIBRO!\n";
			continue;
		}

		if(biblioteca.prestito(libro, cliente))
			cout << "prestito andato a buon fine\n";
		else 
			cout << "non è stato possibile concludere il prestito\n";


		// biblioteca.stampaLibriInPrestito();
		biblioteca.stampaClientiCheDevonoRestituireLibro();

	}

	
	// cout << cliente->getNome() << " " << cliente->getCognome() << endl;

	// cout << endl << endl;
	// biblioteca.stampaLibriInPrestito();
	// cout << endl << endl;
	// biblioteca.rimuoviLibro(0);


	// biblioteca.stampaLibriInPrestito();
}

