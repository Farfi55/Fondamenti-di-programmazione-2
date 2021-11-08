/*
MILLE GRAZIE A ZIO ERNESTO <3 PER QUESTO INESTIMABILE CONTRIBUTO

File creato per facilitare il caricamento di dati nell'esercizio biblioteca
*/

#include <fstream>  					//LA LIBRERIA DA INCLUDERE PER POTER USARE FILE DI TXT COME ARCHIVIO DATI


/* PER LEGGERE DATI DA FILE

Ci sono vari modi per farlo, ma con alcuni ho ricevuto degli errori, per questo motivo uso le set.
La funzione di lettura dati, la lancio all'apertura del mio programma, dopo aver nuovamente inizializzato
un'oggetto biblioteca (da me è un vector di oggetti libro), estraggo dal flusso i vari dati e associo tutto tramite
opportuni set.

Attenzione: in questo modo legge singole parole....per leggere intere stringhe, cercate su google come implementare il getline() in ifstream
*/



void biblioteca::letturaLibri() {

	ifstream miofile;						//INZIALIZZAZIONE DELLO STREAM
	miofile.open("data_libri.txt");			//ASSOCIAMO LO STREAM AL NOSTRO FILE

	// oppure 
	// ifstream miofile("data_libri.txt");


	unsigned cod;							//inizializzo le variabili che userò per 
	string aut;								//leggere il flusso di dati
	string nom;
	string gen;


	miofile >> biblioteca::n_libri;		//la prima cosa che leggo � il mio numero di libri,


	for(int i = 0;i < n_libri;i++) {
		libreria.push_back(*new libro);		//nel mio vector inserisco un oggetto di tipo libro vuoto
		// oppure semplicemente
		// libreria.push_back(libro());

		miofile >> cod; 						//associo dal flusso il codicelibro dal file alla mia variabile	
		libreria[i].setCodUniLib(cod);		//tramite la set, inserisco il valore nell'oggetto precedentemente creato

		miofile >> aut; 						//estraggo dal file il nome dell'autore
		libreria[i].setAutore(aut);		//lo inserisco nell'oggetto preced. creato 

		miofile >> nom; 						//estraggo dal file il titolo del libro
		libreria[i].setNome(nom);			//lo inserisco nell'oggetto preced. creato

		miofile >> gen; 						//idem come su per il genere
		libreria[i].setGenere(gen);
		/*arrivati a questo punto, l'oggetto libro in precedenza creato vuoto,
		sarà stato riempito con i dati provenienti dal file...il  
		fino al completamento della lettura del numero di libri se avete una variabile
		statica che ve li conta, in alternativa potete usare un ciclo while(!miofile.eof())
		che in pratica arriva fino a fine file*/
	}



	miofile.close();						//CHIUDIAMO STREAM E FLUSSO
}



/* PER SCRIVERE DATI SU FILE

La mia funzione lo fa in modalit� TRUNC, ovvero ogni volta che viene richiamat, 
lei cancella il contenuto del file TXT associato e lo riscrive per intero intero ...per i nostri
esercizi non troppo lunghi, va pi� che bene, ma per chi volesse fare diversamente cercat 
come  implementare la modalit� append ...ovvero copia in coda all'ultimoe 
sul file, il nuovo dato...tipo il push_back di vector per intenderci. */

void biblioteca::scritturaLibri() {

	ofstream miofile;					//INIZIALIZZAZIONE STREAM	

	miofile.open("data_libri.txt");		//ASSOCIAZIONE DELLO STREAM AL NOSTRO FILE		

	miofile << biblioteca::n_libri << endl;		//PER PRIMA COSA SALVO NEL FILE IL N� DI LIBRI

	/*CON UN FOR CI LEGGIAMO TUTTI GLI ELEMENTI DEL
	NOSTRO VECTOR DI LIBRI, E COPIAMO OGNI SINGOLO
	ELEMENTO NEL FILE */
	for(int i = 0; i < biblioteca::n_libri;i++) {

		miofile << libreria[i].getCodUniLib() << endl;
		miofile << libreria[i].getAutore() << endl;
		miofile << libreria[i].getNome() << endl;
		miofile << libreria[i].getGenere() << endl;
	}

	miofile.close();					//CHIUSURA FILE E STREAM
}
