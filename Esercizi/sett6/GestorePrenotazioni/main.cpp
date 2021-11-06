#include <iostream>

#include "GestorePrenotazioni.cpp"
using namespace std;

int main() {
    GestorePrenotazioni g;

    g.aggiungiPrenotazione(5, "z0010");
    g.aggiungiPrenotazione(1, "d0004");

    g.aggiungiPrenotazione(5, "c0003");
    g.aggiungiPrenotazione(2, "b0002");
    g.aggiungiPrenotazione(1, "c0003");

    if (g.aggiungiPrenotazione(2, "d0004"))
        cout << "Prenotazione andata a buon fine\n";
    else
        cout << "c'e' stato un errore durante l'aggiunta della prenotazione\n";

    g.stampaPrenotazioni();
    cout << endl;
    g.ordinaPrenotazioni();

    g.stampaPrenotazioni();

    cout << "Inserisci numero prenotazione da eliminare: ";
    int numero;
    cin >> numero;
    if (g.rimuoviPrenotazione(numero))
        cout << "Prenotazione numero: " << numero << " rimossa\n";
    else
        cout << "non e' stato possibile rimuovere la prenotazione numero: "
             << numero << endl;

        g.stampaPrenotazioni();
}
