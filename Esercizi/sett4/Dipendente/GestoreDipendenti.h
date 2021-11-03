#ifndef GESTORE_DIPENDENTI_H
#define GESTORE_DIPENDENTI_H

#include <iostream>
#include <vector>
#include <string>
#include "Dipendente.h"

class GestoreDipendenti{
public:
	GestoreDipendenti() {};

	bool aggiungiDipendente(Dipendente d);
	bool esisteDipendente(string id) const;
	void rimuoviDipendente(string id);
	void stampa() const;
	float calcolaCostoDipendenti() const;

private:
	vector<Dipendente> dipendenti; 
};

#endif
