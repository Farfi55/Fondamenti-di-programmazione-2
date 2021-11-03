#include "GestoreDipendenti.cpp"
#include <iostream>

using namespace std;

int main(){

	GestoreDipendenti g;
	Dipendente d1("0", "Nome1", "Cognome1", 100.0);
	Dipendente d2("1", "Nome2", "Cognome2", 200.0);
	Dipendente d3("2", "Nome3", "Cognome3", 300.0);
	Dipendente d4("0", "Nome4", "Cognome4", 600.0);

	g.aggiungiDipendente(d1);
	g.aggiungiDipendente(d2);
	g.aggiungiDipendente(d3);
	g.aggiungiDipendente(d4);

	if(g.esisteDipendente("1")) cout << "Esiste dipendente id 1" << endl;
	if(g.esisteDipendente("4")) cout << "Esiste dipendente id 4" << endl;
	
	g.stampa();
	cout << endl;

	g.rimuoviDipendente("1");

	g.stampa();

	cout << "Somma degli stipendi: " << g.calcolaCostoDipendenti() << endl;
	return 0;
}
