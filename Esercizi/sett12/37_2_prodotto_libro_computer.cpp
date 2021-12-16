#include <iostream>
#include <string>
using namespace std;

class Prodotto {
protected:
    string id;
    float prezzo;

public:
    Prodotto(string _id, float _prezzo) : id(_id), prezzo(_prezzo) {}

    virtual void stampaPrezzoScontato() = 0;
    friend ostream& operator<<(ostream& out, const Prodotto& prodotto);
    virtual ostream& stampa(ostream& out)  const {
        out << "Prodotto: " << id << ", " << prezzo;
        return out;
    }

};



class Libro : public Prodotto {
protected:
    string titolo;
    string autore;

public:
    Libro(string _id, float _prezzo, string _titolo, string _autore) :
        Prodotto(_id, _prezzo), titolo(_titolo), autore(_autore) {}

    void stampaPrezzoScontato() override {
        cout << prezzo - (prezzo * 0.3f) << endl;
    }

protected:
    ostream& stampa(ostream& out) const override {
        out << "Libro: " << id << ", " << prezzo << ", " <<
            titolo << ", " << autore;
        return out;
    }
};



class Computer : public Prodotto {
protected:
    string modello;

public:
    Computer(string _id, float _prezzo, string _modello) :
        Prodotto(_id, _prezzo), modello(_modello) {}

    void stampaPrezzoScontato() override {
        cout << prezzo - (prezzo * 0.05f) << endl;
    }
};



ostream& operator<<(ostream& out, const Prodotto& prodotto) {
    return prodotto.stampa(out);
}

// ostream& operator<<(ostream& o, const Computer& computer) {
//     o << "Prodotto: " << computer.id << ", " << computer.prezzo;
//     return o;
// }

// ostream& operator<<(ostream& o, const Libro& libro) {

// }


int main(int argc, char const* argv[])
{
    Prodotto* p1 = new Libro("id1", 10.0, "I promessi sposi", "Manzoni");
    Prodotto* p2 = new Computer("id3", 300.0, "asus x456");

    p1->stampaPrezzoScontato();
    p2->stampaPrezzoScontato();

    cout << *p1 << endl;
    cout << *p2 << endl;

    delete p1;
    delete p2;

    return 0;
}

