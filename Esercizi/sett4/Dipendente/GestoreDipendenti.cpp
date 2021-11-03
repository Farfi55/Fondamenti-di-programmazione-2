#include "GestoreDipendenti.h"
#include <iostream>
#include <algorithm>
using namespace std;



bool GestoreDipendenti::aggiungiDipendente(Dipendente d) {
	if(!esisteDipendente(d.getId()))
	{
		dipendenti.push_back(d);
		return true;
	}
	return false;
}


bool GestoreDipendenti::esisteDipendente(string id) const {
	for (int i = 0; i < dipendenti.size(); i++)
		if(dipendenti[i].getId() == id)
			return true;

	return false;	
}


void GestoreDipendenti::rimuoviDipendente(string id) {
	if(!esisteDipendente(id)) return;

	for(vector<Dipendente>::iterator it = dipendenti.begin(); it != dipendenti.end(); it++){
		if(it->getId() == id) {
			dipendenti.erase(it);
			break;
		}
	}

	/*
    elimina tutti i dipendenti aventi id pari a "id" (quadratico)
    vector<Dipendente>::iterator it = dipendenti.begin();
    while(it != dipendenti.end()){
        if(it -> getId() == id)
            dipendenti.erase(it);
        else
            it++;
    }

  	*/
   	//REMOVE_IF
    //Elimina tutti i dipendenti aventi id pari a "id" (lineare) utilizzando le funzioni lambda(tra quadre passo il parametro e tra tonde viene passato ogni volta il dipendente i-esimo)
    //dipendenti.erase(remove_if(dipendenti.begin(), dipendenti.end(), [id](const Dipendente& d){ return id == d.getId();}), dipendenti.end()); 

    //REMOVE
    //Per usare remove invece di remove_if avrei dovuto implementare l'operatore == in Dipendente che controlla se gli id sono uguali e, prima di invocare il remove, avrei dovuto creare un
    //dipendente fittizio con l'id passato come parametro
    /* 
        Dipendente d; 
        d.setId(id);
        dipendenti.erase(remove(dipendenti.begin(), dipendenti.end(), d), dipendenti.end()); 
    */
   
}


void GestoreDipendenti::stampa() const {
	for (int i = 0; i < dipendenti.size(); i++)
	{
		cout << dipendenti[i];
	}	
}


float GestoreDipendenti::calcolaCostoDipendenti() const {
	float sum = 0.0;
	for (int i = 0; i < dipendenti.size(); i++)
	{
		sum += dipendenti[i].getStipendio();
	}

	return sum;
}
