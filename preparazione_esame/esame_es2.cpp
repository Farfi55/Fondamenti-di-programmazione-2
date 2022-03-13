#include <vector>
#include <limits>

using namespace std;


class GestoreValori {
protected:
	vector<vector<int>> coppie = vector<vector<int>>(256);
	unsigned n_coppie = 0;

public:
	void inserisciCoppia(char c, int i) {
		coppie[c].push_back(i);
		n_coppie++;
	}

	unsigned numeroCoppie() const {
		return n_coppie;
	}

	virtual int getValore() const {
		return -1;
	}
};


class GestoreValoriA : public GestoreValori {
public:
	int getValore() const override {
		int somma = 0;
		for(int i = 0; i < GestoreValori::coppie['a'].size(); i++) {
			somma += GestoreValori::coppie['a'][i];
		}
		return somma;
	}

};


class GestoreValoriB : public GestoreValori {
public:
	int getValore() const override {
		int n_coppie_b = GestoreValori::coppie['b'].size();
		if(n_coppie_b == 0)
			return 0;

		int somma = 0;
		for(int val : (GestoreValori::coppie['b'])) {
			somma += val;
		}
		return (somma / n_coppie_b);
	}
};
