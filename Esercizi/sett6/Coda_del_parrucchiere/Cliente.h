#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>
using std::cout;
using std::ostream;
using std::istream;
using std::string;

class Cliente {
    friend ostream& operator<<(ostream& o, const Cliente& c);
    friend istream& operator>>(istream& i, Cliente& c);

private:
    int id;
    string nome;
    string trattamento;
    int durataTrattamento;
    int prezzoTrattamento;

public:
    Cliente() {}
    Cliente(int id, string nome, string trattamento, int durataTrattamento, int prezzoTrattamento) :
        id(id),
        nome(nome),
        trattamento(trattamento),
        durataTrattamento(durataTrattamento),
        prezzoTrattamento(prezzoTrattamento) {}

    Cliente(const& Cliente);

    int getId() const { return id; }
    string getNome() const { return nome; }
    string getTrattamento() const { return trattamento; }
    int getDurataTrattamento() const { return durataTrattamento; }
    int getPrezzoTrattamento() const { return prezzoTrattamento; }
};

ostream& operator<<(ostream& o, const Cliente& c) {
    o << "[" << c.id << "]\tnome: " << c.nome
        << "\ttrattamento: " << c.trattamento
        << "\n\tdurata: " << c.durataTrattamento
        << "min\tprezzo: " << c.prezzoTrattamento << " euro\n";
    return o;
}


istream& operator>>(istream& i, Cliente& c) {
    i >> c.id >> c.nome >> c.trattamento >> c.durataTrattamento >> c.prezzoTrattamento;
    return i;
}


#endif
