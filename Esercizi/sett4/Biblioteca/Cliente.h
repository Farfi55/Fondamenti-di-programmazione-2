#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
// #include "Libro.h"

using namespace std;

class Cliente {
   private:
    unsigned ID;
    static unsigned IDCounter;
    string nome;
    string cognome;
    string codiceFiscale;

    // Libro* libroPresoInPrestito = nullptr;

    // if(LibroPresoInPrestito != nullptr)

    bool _deveRestituireLibro = false;

   public:
    Cliente();
    Cliente(string nome, string cognome, string codiceFiscale);
    Cliente(const Cliente& cliente);

    unsigned getID() const { return ID; }
    string getNome() const { return nome; }
    string getCognome() const { return cognome; }
    string getCodiceFiscale() const { return codiceFiscale; }
    bool deveRestituireLibro() const { return _deveRestituireLibro; }


    void setNome(string nome) { this->nome = nome; }
    void setCognome(string cognome) { this->cognome = cognome; }
    void setCodiceFiscale(string codiceFiscale) {
        this->codiceFiscale = codiceFiscale;
    }
    void setDeveRestituireLibro(bool value) { _deveRestituireLibro = value; }

    Cliente operator=(const Cliente&);
};
unsigned Cliente::IDCounter = 0;

Cliente::Cliente() {
    IDCounter += (nome.size() + cognome.size()) % 10;
    ID = IDCounter;

    nome = "";
    cognome = "";
    codiceFiscale = "";
}

Cliente::Cliente(string nome, string cognome, string codiceFiscale) {
    IDCounter += (nome.size() + cognome.size()) % 10;
    ID = IDCounter;


    this->nome = nome;
    this->cognome = cognome;
    this->codiceFiscale = codiceFiscale;
}

Cliente::Cliente(const Cliente& cliente) {
	this->ID = cliente.ID;
	this->nome = cliente.nome;
	this->cognome = cliente.cognome;
	this->codiceFiscale = cliente.codiceFiscale;
}

Cliente Cliente::operator=(const Cliente& cliente) {
    this->ID = cliente.ID;
    this->nome = cliente.nome;
    this->cognome = cliente.cognome;
    this->codiceFiscale = cliente.codiceFiscale;

    return *this;
}

#endif
