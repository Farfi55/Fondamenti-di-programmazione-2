#include "Documento.h"
#include <iostream>

using std::cout;

int main() {
    Documento doc("Alessio", "Documento.h", 1024);
    DocumentoPDF pdf("Gennaro", "Erecizio_308.pdf", 4096, false);
    DocumentoMP3 mp3("Adriana", "Quanto ti vorrei by Chiello.mp3", 17054, 170.0);

    cout << doc.getProprietario() << endl;
    cout << doc.getDescrizione() << endl;
    cout << doc.getDimensioneFile() << "Kb\n\n";

    cout << pdf.getProprietario() << endl;
    cout << pdf.getDescrizione() << endl;
    cout << pdf.getDimensioneFile() << "Kb\n";
    if(!pdf.getFirmato()) cout << "NON ";
    cout << "FIRMATO!\n\n";


    cout << mp3.getProprietario() << endl;
    cout << mp3.getDescrizione() << endl;
    cout << mp3.getDimensioneFile() << "Kb\n";
    cout << mp3.getDurata() << "secondi\n\n";


}
