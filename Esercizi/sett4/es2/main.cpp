#include "Studente.cpp"

#include <iostream>

using namespace std;


bool bestStudents(Studente studenti[], unsigned numeroStudenti);
unsigned numeroEsamiAllaLaurea(Studente studenti[], unsigned numeroStudenti);
bool stessiVoti(const Studente& s1, const Studente& s2);
string getMatricolaStudenteGiovaneEBravo(Studente studenti[], unsigned numeroStudenti);

int main(){
	cout << "inserisci il numero di studenti: ";
	int numero_studenti; cin >> numero_studenti;

	Studente* studenti = new Studente[numero_studenti];

	for (int i = 0; i < numero_studenti; i++)
	{
		cout << "Sto inserendo lo studente numero " << (i+1) << endl;
		cin >> studenti[i];
	}


	for (int i = 0; i < numero_studenti; i++)
	{
		cout << "Studente: " << (i+1) << endl;
		cout << studenti[i];	
		cout << "Media: " << studenti[i].getMediaVoti() << endl;
		cout << "Media ponderata: " << studenti[i].getMediaPonderata() << "\n\n";

	}


	// 

	//test metodi

	if(bestStudents(studenti, numero_studenti)) cout << "I migliori studenti di sempre :)\n";
	else cout << "Tipici studenti che non concludono gli studi\n";


	cout << "Mancano solo " << numeroEsamiAllaLaurea(studenti, numero_studenti) << " esami ad uno studente per laurearsi, tieni duro\n";

	for (int i = 0; i < numero_studenti - 1; ++i)
		for(int j = i + 1; j < numero_studenti; ++j)
			if(stessiVoti(studenti[i], studenti[j]))
				cout << "matricole: " << studenti[i].getMatricola() << " e " << studenti[j].getMatricola() <<
				" hanno preso gli stessi voti\n";
		

	cout << "La matricola piu' giovane e brava e': " << getMatricolaStudenteGiovaneEBravo(studenti, numero_studenti) << endl;

	delete [] studenti;
	
	return 0;

}



bool bestStudents(Studente studenti[], unsigned numeroStudenti){
	for(int i = 0; i < numeroStudenti; ++i){
		if(studenti[i].getMediaPonderata() < 28) return false;
	}

	return true;
}

unsigned numeroEsamiAllaLaurea(Studente studenti[], unsigned numeroStudenti){
	unsigned maxEsamiSostenuti = studenti[0].getEsamiSostenuti();
	
	for (int i = 1; i < numeroStudenti; i++)
	{
		if(studenti[i].getEsamiSostenuti() > maxEsamiSostenuti)
			maxEsamiSostenuti = studenti[i].getEsamiSostenuti();		
	}

	return 24 - maxEsamiSostenuti;
}

bool stessiVoti(const Studente& s1, const Studente& s2){
	if(s1.getEsamiSostenuti() != s2.getEsamiSostenuti())
		return false;
	
	unsigned numeroVoti[31];
	
	for (int i = 0; i < s1.getEsamiSostenuti(); i++)
	{
		numeroVoti[s1.getVotoI(i)]++;
		numeroVoti[s2.getVotoI(i)]--;
	}

	for (int i = 0; i < 31; i++)
		if(numeroVoti[i] != 0) 
			return false;
	
	return true;
}


string getMatricolaStudenteGiovaneEBravo(Studente studenti[], unsigned numeroStudenti){

	bool piuStudentiConStessaMedia = false;
	float mediaMigliore = 0;
	unsigned indiceMigliorStudente = -1;


	for (int i = 0; i < numeroStudenti; ++i){
		if (studenti[i].getEta() <= 20 && studenti[i].getEsamiSostenuti() > 3)	{
			if(studenti[i].getMediaVoti() > mediaMigliore){
				mediaMigliore = studenti[i].getMediaVoti();
				indiceMigliorStudente = i;
			}
			else if(studenti[i].getMediaVoti() == mediaMigliore)
				if(studenti[i].getEta() < studenti[indiceMigliorStudente].getEta())
					indiceMigliorStudente = i;
		}
	}

	if(indiceMigliorStudente == -1) return "- - -";
	else return studenti[indiceMigliorStudente].getMatricola();
}
