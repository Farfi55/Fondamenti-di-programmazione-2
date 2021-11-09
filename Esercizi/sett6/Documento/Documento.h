#include <string>
#include <iostream>

using namespace std;

class Documento {
protected:
    string proprietario;
    string descrizione;
    int dimensioneFile;

public:
    Documento() {}

    Documento(string proprietario, string descrizione, int dimensioneFile) :
        proprietario{ proprietario },
        descrizione{ descrizione },
        dimensioneFile{ dimensioneFile } {}

    Documento(const Documento& doc) :
        proprietario{ doc.proprietario },
        descrizione{ doc.descrizione },
        dimensioneFile{ doc.dimensioneFile } {}

    string getProprietario() const { return proprietario; }
    string getDescrizione() const { return descrizione; }
    int getDimensioneFile() const { return dimensioneFile; }

    void setProprietario(string proprietario) { this->proprietario = proprietario; }
    void setDescrizione(string descrizione) { this->descrizione = descrizione; }
    void setDimensioneFile(int dimensioneFile) { this->dimensioneFile = dimensioneFile; }
};


class DocumentoPDF : public Documento {
protected:
    bool firmato;
public:
    DocumentoPDF() {}

    DocumentoPDF(string proprietario, string descrizione, int dimensioneFile, bool firmato) :
        Documento{ proprietario, descrizione, dimensioneFile },
        firmato{ firmato } {}

    DocumentoPDF(const DocumentoPDF& doc) :
        Documento{ doc.proprietario, doc.descrizione, doc.dimensioneFile },
        firmato{ doc.firmato } {}

    bool getFirmato() const { return firmato; }
    void setFirmato(bool firmato) { this->firmato = firmato; }
};

class DocumentoMP3 : public Documento {
protected:
    float durata;
public:
    DocumentoMP3() {}

    DocumentoMP3(string proprietario, string descrizione, int dimensioneFile, float durata) :
        Documento{ proprietario, descrizione, dimensioneFile },
        durata{ durata } {}

    DocumentoMP3(const DocumentoMP3& doc) :
        Documento{ doc.proprietario, doc.descrizione, doc.dimensioneFile },
        durata{ doc.durata } {}

    float getDurata() const { return durata; }
    void setDurata(float durata) { this->durata = durata; }
};

