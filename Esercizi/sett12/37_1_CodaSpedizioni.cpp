#include <list>
#include <iostream>
using namespace std;


bool precede(Spedizione* s1, Spedizione* s2);




typedef list<Spedizione*> base;


class CodaSpedizioni : protected base
{
private:
    // int subset_1_end;
    // int subset_2_end;
public:
    CodaSpedizioni() : base() {};

    void add(Spedizione* spedizione);
    void remove();
    Spedizione* next() const { return base::front(); }

    unsigned int size() const { return base::size(); }
};


void CodaSpedizioni::add(Spedizione* spedizione) {

    for(auto it = base::begin(); it < base::end(); it++) {
        if(precede(soluzione, it*)) {
            base::insert(it, soluzione);
            return;
        }
    }
    base::push_back(soluzione);
}

/*
    const int codice_spedizione = spedizione->getCodice();
    auto it = base::begin();

    if(codice_spedizione == 1) {
        const int val = spedizione.getValore();
        for(; it < base::begin() + subset_1_end; it++) {
            if((it**).getValore() > val)
                break;
        }
        subset_1_end++;
        subset_2_end++;
    }
    else if(codice_spedizione == 2) {
        const int peso = spedizione.getPeso();

        it += subset_1_end;
        for(; it < base::begin() + subset_2_end; it++) {
            if((it**).getPeso() > peso)
                break;
        }
        subset_2_end++;
    }
    else {
        const int id = spedizione.getId();
        it += subset_2_end;
        for(; it < base::end(); it++) {
            if((it**).getId() < id)
                break;
        }
        subset_2_end++;
    }

    list<Spedizione*>::insert(it, spedizione);
    */


void CodaSpedizioni::remove() {

}


bool precede(Spedizione* s1, Spedizione* s2) {
    if(s1->getCodice() == 1 && s2->getCodice() != 1) return true;
    if(s2->getCodice() == 1 && s1->getCodice() != 1) return false;
    if(s1->getCodice() == 1 && s2->getCodice() == 1)
        return s1->getValore() < s2->getValore();

    // da qui sappiamo che il codice di s1 e s3 è sicuramente diverso da 1
    if(s1->getCodice() == 2 && s2->getCodice() != 2) return true;
    if(s2->getCodice() == 2 && s1->getCodice() != 2) return false;
    if(s1->getCodice() == 2 && s2->getCodice() == 2)
        return s1.getPeso() < s2->getPeso();

    // da qui in poi sappiamo che il codice di s1 e s2 è sicuramente diverso da 1 e 2
    return s1->setId() < s2->getId();
}

