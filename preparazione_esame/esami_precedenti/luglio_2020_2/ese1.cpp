/*
https://prototypes.mat.unical.it/asd/traccia_online_luglio2020_2.pdf

ESERCIZIO 1
Dato un albero binario A di numeri interi, scrivere una funzione chiamata esercizio1 che prenda in input A e
restituisca true se la somma dei nodi liberi è uguale alla somma dei nodi vincolati, altrimenti f 
nodo si dice libero quando si trova sul lato estremo sinistro o destro dell’albero (si faccia rifo 
all’esempio). Tutti gli altri nodi più interni sono nodi vincolati. Si noti come la radice dell’albero A èempre 
un nodo libero.

L’albero è rappresentato da una classe AlberoB. Sia a una istanza della classe, l’interfaccia è la seguente:
	• a.figlio(SIN/DES) restituisce il figlio sinistro o destro dell’albero A se esiste, nti 
	restituisce la costante NULLO;
	• a.padre() restituisce il padre dell’albero a se esiste, altrimenti restituisce la costante NULLO;
	• a.radice() restituisce il valore informativo associato all’albero a (il valore interouto 
	all’interno del nodo);
	• a.foglia() restituisce true se l’albero a è una foglia, altrimenti false.

*/


void dfs(const AlberoB& a, int& somma_lib, int& somma_vin, bool sempre_sin, bool sempre_des) {
	if(sempre_sin || sempre_des) somma_lib += a.radice();
	else somma_vin += a.radice();


	if(a.figlio(SIN) != NULLO) {
		dfs(a.figlio(SIN), somma_lib, somma_vin, sempre_sin, false);
	}
	if(a.figlio(DES) != NULLO) {
		dfs(a.figlio(DES), somma_lib, somma_vin, false, sempre_des);
	}
}


bool esercizio1(const AlberoB& a) {
	int somma_lib = 0;
	int somma_vin = 0;

	dfs(a, somma_lib, somma_vin, true, true);

	return somma_lib == somma_vin;
}
