/*
Esercizio 2.
Assumendo di avere una classe AutoF1 che implementa i metodi :

int getNumeroPilota(), string getNomePilota(), string getSquadra()

scrivere opportunamente una classe Campionato
che consenta di implementare le seguenti funzionalità :

void inserisci Risultato(string gara, AutoF1 a, int pos)
che deve consentire di memorizzare, uno per volta, i risultati di una gara per tutte le auto partecipanti

 string getPilotaClassifica(int pos)
che deve restituire il nome del pilota in posizione pos nella classifica parziale piloti del campionato in base ai risultati attualmente memorizzati(secondo le regole di calcolo riepilogate di seguito)

string getSquadraClassifica(int pos)
che deve restituire il nome della squadra in posizione pos nella classifica parziale squadre del campionato in base ai risultati attualmente memorizzati(secondo le regole di calcolo riepilogate di seguito)


Regole per il calcolo del punteggio per la classifica piloti :
sia pos la posizione di arrivo nella gara dal pilota p,
i nuovi punti acquisiti da p sono dati dalla formula :
11 - pos se pos <= 10
O se pos > 10

Regole per il calcolo del punteggio per la classifica squadre :
Il punteggio di una squadra è dato dalla somma dei punteggi dei piloti appartenenti a quella squadra

*/
#include <string>
#include <vector>
#include <pair>
#include <map>

using namespace std;

class AutoF1 {
	int numero_pilota;
	string nome_pilota;
	string squadra;

public:
	AutoF1(int numero, const string& nome, const string& squadra_) :
		numero_pilota(numero), nome_pilota(nome), squadra(squadra_) {}

	AutoF1(const AutoF1& a) :
		numero_pilota(a.numero_pilota), nome_pilota(a.nome_pilota), squadra(a.squadra) {}

	int getNumeroPilota() const { return numero_pilota; }
	string getNomePilota()  const { return nome_pilota; }
	string getSquadra() const { return squadra; }
};


class Campionato {
	vector<pair<int, string>> classifica_piloti;
	vector<pair<int, string>> classifica_squadre;


public:
	void inserisci_risultato(string gara, AutoF1& a, int pos) {
		int punti = pos > 10 ? 0 : 11 - pos;


		bool presente = false;
		for(int i = 0; i < classifica_piloti.size() && !presente; i++) {
			if(classifica_piloti[i].second == a.getNomePilota()) {
				classifica_piloti[i].first += punti;
				presente = true;
			}
		}
		if(!presente)
			classifica_piloti.emplace_back(punti, a.getNomePilota());

		presente = false;
		for(int i = 0; i < classifica_squadre.size() && !presente; i++) {
			if(classifica_squadre[i].second == a.getSquadra()) {
				classifica_squadre[i].first += punti;
				presente = true;
			}
		}
		if(!presente)
			classifica_squadre.emplace_back(punti, a.getSquadra());

		sort(classifica_piloti.begin(), classifica_piloti.end());
		sort(classifica_squadre.begin(), classifica_squadre.end());
	}

	string getPilotaClassifica(int pos) {
		return pos >= classifica_piloti.size() ? "" : classifica_piloti[pos].second;
	}

	string getSquadraClassifica(int pos) {
		return pos >= classifica_squadre.size() ? "" : classifica_squadre[pos].second;
	}
};
