#ifndef GRAFO_PESATO
#define GRAFO_PESATO

#include <vector>
#include "grafo.h"

using Weights = std::vector<int>;

// eredita da un grafo orientato
class GrafoPesato : protected Grafo {
protected:
	// matrice che contiene i pesi
	std::vector<Weights> weights;

	void initWeights(unsigned n) {
		this->weights = std::vector<Weights>(n);
		for(unsigned i = 0; i < n; i++)
			this->weights[i] = Weights(n, -1);
	}

public:
	GrafoPesato(unsigned n) : Grafo(n) {
		initWeights(n);
	}

	// inserisce o elimina un arco (secondo b)
	// per l'inserimento, l'arco avrÃ  peso w
	// per l'eliminazione, l'arco avrÃ  peso -1
	void operator()(unsigned i, unsigned j, bool b, int w) {
		Grafo::operator()(i, j, b);
		if(b)
			this->weights[i][j] = w;
		else
			this->weights[i][j] = -1;
	}

	// modifica il peso di un arco (se esistente)
	void operator()(unsigned i, unsigned j, int w) {
		if((*this)(i, j))
			this->weights[i][j] = w;
	}


	// funzioni const
	unsigned n() const { return Grafo::n(); }
	unsigned m() const { return Grafo::m(); }
	bool operator()(unsigned i, unsigned j) const {
		return Grafo::operator()(i, j);
	}

	// ritorna il peso dell'arco (i,j) (se esso esiste) altrimenti -1
	int w(unsigned i, unsigned j) const {
		if(Grafo::operator()(i, j))
			return this->weights[i][j];
		return -1;
	}
};

#endif
