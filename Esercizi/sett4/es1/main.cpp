#include "Programmatore.h" 
#include <iostream> 
#include <string>
#include <cassert>


using namespace std;

const int numero_programmatori = 5;

int main(){
	Programmatore programmatori[numero_programmatori];

	for (int i = 0; i < numero_programmatori; i++){
		cin >> programmatori[i];
	}

}


unsigned getNumeroProgrammatoriPerNome(Programmatore programmatori[], string nome){
	unsigned count = 0;

	for (int i = 0; i < numero_programmatori; i++)
		if (programmatori[i].getNome() == nome)
			count++;
	
	return count;
}


/**
 * restituire lo stipendio medio dei senior
 */

float getStipendioMedioSenior(Programmatore programmatori[]){
	float somma_stipendi = 0;
	unsigned numero_senior = 0;
	for (int i = 0; i < numero_programmatori; i++)
	{
		if(programmatori[i].isSenior()){
			somma_stipendi += programmatori[i].getStipendio();
			++numero_senior;
		}
	}
	if(numero_senior == 0)
		return 0;
	return somma_stipendi/numero_senior;
	

}

// Restituisce il programmatore, non ancora senior, con più anni di esperienza
const Programmatore& getJuniorPiuEsperto(Programmatore programmatori[]){
	unsigned anni_esperienza_max = 0;
	int indice_programmatore = -1;

	for (int i = 0; i < numero_programmatori; ++i){
		if(!programmatori[i].isSenior()){
			if(indice_programmatore == -1 || programmatori[i].getAnniEsperienza() > indice_programmatore)
			{
				indice_programmatore = i;
				anni_esperienza_max = programmatori[i].getAnniEsperienza();
			}
		}
	}

	assert(indice_programmatore != -1);

	return programmatori[indice_programmatore];

}

//restituisce la differenza d'età tra il più anziano e l più giovane del gruppo
unsigned maxDifferenzaEta(Programmatore programmatori[]){
	
	unsigned max_eta, min_eta;
	max_eta = min_eta = programmatori[0].getEta();

	for (int i = 1; i < numero_programmatori; ++i){
		unsigned eta = programmatori[i].getEta();
		if(eta > max_eta) max_eta = eta;		 
		else if(eta < min_eta) min_eta = eta;		 
	}

	return max_eta - min_eta;

}



bool anzianita(Programmarore programmatori[]){

	for (int i = 0; i < numero_programmatori; ++i) {
		for (int j = 0; j < numero_programmatori; ++j) {
			if(programmatori[i].getEta() > programmatori[j].getEta())
				if(programmatori[i].getStipendio() <= programmatori[j].getStipendio())
					return false;
		}
		
	}
	return true;
}


bool anzianietaOrdinata(Programmatore programmatori[]){
	for(int i = 1; i < numero_programmatori; ++i){
		if(programmatori[i].getStipendio() < programmatori[i-1])
			return false;
	}
	return true;

}
