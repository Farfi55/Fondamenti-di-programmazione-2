#include "Studente.h"

ostream& operator<< (ostream& out, const Studente& stud){
	out << "matricola: " << stud.matricola << endl;
	out << "eta: " << stud.eta << endl;

	for (int i = 0; i < stud.esami_sostenuti; ++i){
		out << "esame[" << i+1 << "]: " << stud.nomi_esami[i] <<
		": (voto: " << stud.voti_esami[i] << ", cfu: " << stud.cfu_esami[i] << " )\n";
	}
	return out;
}

istream& operator>> (istream& in, Studente& stud){
	cout << "inserisci matricola: ";
	string matricola; in >> matricola; stud.setMatricola(matricola);

	cout << "inserisci eta: ";
	unsigned eta; cin >> eta; stud.setEta(eta);

	cout << "inserisci numero esami da aggiungere: ";
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cout << "inserisci dati esame [" << i+1 << "]\n";
		cout << "nome: "; string nome; cin >> nome;
		cout << "voto: "; unsigned voto; cin >> voto;
		cout << "cfu: "; unsigned cfu; cin >> cfu;
		
		stud.aggiungiEsame(nome, voto, cfu);	
	}
	return in;
}


Studente::Studente(){
	matricola = "";
	eta = 0;
	esami_sostenuti = 0;
}

Studente::Studente(string matricola, unsigned eta){
	this->matricola = matricola;
	this->eta = eta;
	esami_sostenuti = 0;
}

void Studente::aggiungiEsame(string esame, unsigned voto, unsigned cfu){
	if(esami_sostenuti == 24) return;
	
	nomi_esami[esami_sostenuti] = esame;
	voti_esami[esami_sostenuti] = voto;
	cfu_esami[esami_sostenuti] = cfu;
	++esami_sostenuti;
}

void Studente::rimuoviUltimoEsame(){
	if(esami_sostenuti == 0) return;

	--esami_sostenuti;
	nomi_esami[esami_sostenuti] = "";
	voti_esami[esami_sostenuti] = 0;
	cfu_esami[esami_sostenuti] = 0;
}

float Studente::getMediaVoti() const {
	if(esami_sostenuti == 0) return 0;

	unsigned somma = 0;
	for (int i = 0; i < esami_sostenuti; ++i){
		somma += voti_esami[i];
	}

	return somma/esami_sostenuti;
}

float Studente::getMediaPonderata() const {
	if(esami_sostenuti == 0) return 0;

	unsigned somma_voti_ponderati = 0, cfu_totali = 0;
	for (int i = 0; i < esami_sostenuti; ++i){
		somma_voti_ponderati += voti_esami[i] * cfu_esami[i];
		cfu_totali += cfu_esami[i];
	}

	return somma_voti_ponderati/cfu_totali;
}


unsigned Studente::getVotoPiuBasso() const {
	if(esami_sostenuti == 0) return 0;

	unsigned voto_minore = voti_esami[0];

	for (int i = 0; i < esami_sostenuti; i++)
	{
		if(voti_esami[i] < voto_minore)
			voto_minore = voti_esami[i];
	}

	return voto_minore;
}


unsigned Studente::getVotoPiuAlto() const {
	if(esami_sostenuti == 0) return 0;

	unsigned voto_maggiore = voti_esami[0];

	for (int i = 0; i < esami_sostenuti; i++)
	{
		if(voti_esami[i] > voto_maggiore)
			voto_maggiore = voti_esami[i];
	}

	return voto_maggiore;

}

unsigned Studente::getVotoI(unsigned i) const {
	if(i >= esami_sostenuti ) return 0;
	return voti_esami[i];	
}
