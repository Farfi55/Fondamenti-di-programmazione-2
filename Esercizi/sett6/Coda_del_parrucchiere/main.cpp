#include <iostream>
#include <queue>

using namespace std;

#include "Cliente.h"

void stampaMenu();
void stampaOrario(int minuti);
void stampa(queue<Cliente> coda);

int main() {
    queue<Cliente> coda;
    char scelta;
    unsigned incasso_attuale = 0;
    const unsigned tempo_apertura = 8 * 60;
    unsigned tempo_trascorso = 0;
    unsigned tempo_attesa = 0;

    stampaMenu();
    do {
        cout << "Segli funzione: ";
        cin >> scelta;
        switch(scelta) {
            // inserisci cliente
            case '1': {
                cout << "Inserisci:\nID, NOME, TRATTAMENTO, DURATA_TRATT., PREZZO_TRATT.\n";
                Cliente c;
                cin >> c;
                coda.push(c);
                tempo_attesa += c.getDurataTrattamento();

                cout << "Cliente inserito\n\n";
                break;
            }
                    // esegui prossimo trattamento
            case '2': {
                if(coda.size() > 0) {
                    Cliente c = coda.front();
                    coda.pop();

                    incasso_attuale += c.getPrezzoTrattamento();
                    tempo_trascorso += c.getDurataTrattamento();
                    tempo_attesa -= c.getDurataTrattamento();

                    cout << "E' stato servito il cliente " << c.getNome() << endl;
                    cout << "Il trattamento: " << c.getTrattamento()
                        << " ha impiegato " << c.getDurataTrattamento() << "min\n";
                }

                else {
                    cout << "Non ci sono clienti in fila\n";
                }
                break;
            }
                    // prossimo orario disponibile
            case '3': {
                cout << "Orario attuale: ";
                stampaOrario(tempo_apertura + tempo_trascorso);
                cout << endl;

                cout << "Tempo attesa: ";
                stampaOrario(tempo_attesa);
                cout << endl;

                cout << "Prossimo orario disponibile: ";
                stampaOrario(tempo_apertura + tempo_trascorso + tempo_attesa);
                cout << endl;
                break;
            }
                    // stampa tutti i clienti in fila
            case '4': {
                stampa(coda);
                break;
            }
                    // stampa orario
            case '5': {
                cout << "L'orario attuale e': ";
                stampaOrario(tempo_apertura + tempo_trascorso);
                break;
            }
                    // stampa incasso
            case '6': {
                cout << "L'incasso fino ad ora e': " << incasso_attuale << endl;
                break;
            }
                    // esci
            case '0': {
                cout << "arrivederci!\n\n";
                return 0;
            }

            default:
            break;
        }
    } while(scelta != '0');

    return 0;
}



void stampa(queue<Cliente> coda) {
    while(!coda.empty()) {
        cout << coda.front() << endl;
        coda.pop();
    }
}


void stampaOrario(int minuti) {
    cout << (minuti / 60) << "h:" << (minuti % 60) << "min\n";
    // cout << minuti << "min\n";
}


void stampaMenu() {
    cout << "Benvenuti dal parrucchiere. Orario di apertura ore 8:00\n\n";
    cout << "Inserisci 1 per inserire un nuovo cliente;\n";
    cout << "Inserisci 2 per esseguire il trattamento del prossimo cliente;\n";
    cout << "Inserisci 3 per chiedere il prossimo orario disponibile;\n";
    cout << "Inserisci 4 per stampare tutti i clienti in fila;\n";
    cout << "Inserisci 5 per stampare l'orario attuale;\n";
    cout << "Inserisci 6 per stampare l'incasso attuale;\n";
    cout << "Inserisci 0 per uscire;\n";
}
