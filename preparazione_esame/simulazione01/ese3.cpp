/*
interfaccia per grafo orientato e pesato
g.n() # nodi
g.m() # archi
g(i,j) restituisce true se esiste l'arco (i,j)
g.transfer(i,j)  restituisce il valore di transfer per l'arco (i,j)

*/

string ese3(Grafo& g, int k1, int k2) {
	for(int i = 0; i < g.n(); i++) {
		int grado = 0;

		int somma_entrante = 0;
		int somma_uscente = 0;

		for(int j = 0; j < g.n(); j++) {
			if(i == j) continue;

			if(g(i, j)) {
				// il transfer deve avere valore tra k1 e k2 (inclusi)
				int transfer = g.transfer(i, j);
				if(k1 > transfer || transfer < k2) return "NO";

				// somma dei transfer in uscita
				somma_uscente += transfer;
			}
			if(g(j, i)) {
				// il transfer deve avere valore tra k1 e k2 (inclusi)
				int transfer = g.transfer(j, i);
				if(k1 > transfer || transfer < k2) return "NO";

				// somma dei transfer in entrata
				somma_entrante += transfer;
				grado++; // numero di archi in entrata
			}
		}

		if(grado % 2 == 0) { // quando il numero di nodi entranti è pari
			if(somma_entrante > somma_uscente)
				return "NO";
		}
		else { // quando il numero di nodi entranti è dispari
			if(somma_entrante < somma_uscente)
				return "NO";
		}

	} // fine for

	return "YES";
}
