//10-12-2021 10:29
#include <iostream>
#include <vector>
#include <array>

using namespace std;

// TODO FINIRE

struct Soluzione
{
    uint8_t mappa[9][9];

    // riga corrente 
    uint8_t riga;

    // colonna corrente 
    uint8_t colonna;

    // dove l' i-esimo elemento dell'array più interno rappresente se l'elemento i è presente

    // nella riga indicata dall'array esterno
    bool valori_in_riga[9][9];

    // nella colonna indicata dall'array esterno
    bool valori_in_colonna[9][9];

    // nella sottomatrice (i,j)
    // dove i è la riga
    //    e j è la colonna 
    bool valori_in_sottomatrice[3][3][9];


    Soluzione(uint8_t m[9][9]) : riga(0), colonna(0) {
        for(uint8_t i = 0; i < 9; i++)
            for(uint8_t j = 0; j < 9; j++) {
                uint8_t x = m[i][j];
                mappa[i][j] = x;
                valori_in_riga[i][x] = (x != 0);
                valori_in_colonna[j][x] = (x != 0);
                valori_in_sottomatrice[i / 3][j / 3][x] = (x != 0);

            }
    }

};

bool solve(Soluzione& sol);
bool canAdd(uint8_t val, const Soluzione& sol);
bool isComplete(const Soluzione& sol);
void add(int val, Soluzione& sol);
void remove(Soluzione& sol);

void incrementaCella(Soluzione& sol);
void decrementaCella(Soluzione& sol);

void stampaMappa(uint8_t mappa[9][9]);

int main(int argc, char const* argv[])
{
    uint8_t mappa[9][9];
    for(uint8_t i = 0; i < 9; i++)
        for(uint8_t j = 0; j < 9; j++)
            mappa[i][j] = 0;

    int riga, colonna, valore;
    cout << "Inserisci -1 per uscire." << endl;
    cout << "altrimenti: riga, colonna, valore." << endl;

    while(true) {
        cout << "> ";
        cin >> riga;
        if(riga == -1)
            break;

        cin >> colonna >> valore;

        mappa[riga][colonna] = valore;
        cout << "inserita (" << riga << ", " << colonna << "): " << valore << endl;


    }
    stampaMappa(mappa);

    Soluzione s(mappa);

    cin.get();

    if(solve(s)) {
        cout << "trovata soluzione\n";
        stampaMappa(s.mappa);
    }
    else cout << "soluzione non trovata";

    return 0;
}


void stampaMappa(uint8_t mappa[9][9]) {
    cout << "\n_____________________________________\n\n";
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {

            if(!(j % 3)) cout << "|";
            else cout << ",";
            if(mappa[i][j] == 0)
                cout << " . ";
            else cout << " " << +mappa[i][j] << " ";
            // visto che la mappa è formata da uint8_t (AKA unsigned char)
            // c++ lo stampa come fosse un carattere, aggiungendo '+' davanti
            // alla variabile, indichiamo che lo vogliamo stampare come un numero
            // https://stackoverflow.com/questions/15585267/cout-not-printing-unsigned-char

        }
        if((i % 3) == 2)
            cout << "|\n_______________________________________\n\n";
        else
            cout << "|\n|           |           |           |\n";


    }
}


bool solve(Soluzione& soluzione) {
    // la posizione corrente ha già un valore 
    if(soluzione.riga < 9 && soluzione.colonna < 9 &&
        soluzione.mappa[soluzione.riga][soluzione.colonna] != 0) {

        if(isComplete(soluzione)) return true;

        incrementaCella(soluzione);

        if(solve(soluzione))
            return true;

        decrementaCella(soluzione);
        return false;
    }

    uint8_t val = 1;
    while(val <= 9) {
        if(canAdd(val, soluzione)) {
            add(val, soluzione);

            if(isComplete(soluzione)) return true;

            if(solve(soluzione)) return true;

            remove(soluzione);
        }
        val++;
    }
    return false;
}


bool canAdd(uint8_t val, const Soluzione& sol) {
    return (
        (!sol.valori_in_colonna[sol.colonna][val]) &&
        (!sol.valori_in_riga[sol.riga][val]) &&
        (!sol.valori_in_sottomatrice[sol.riga / 3][sol.colonna / 3][val])
        );
}


bool isComplete(const Soluzione& sol) {
    return (sol.riga == 8 && sol.colonna == 8);
}

void add(int val, Soluzione& sol) {
    sol.mappa[sol.riga][sol.colonna] = val;
    sol.valori_in_sottomatrice[sol.riga / 3][sol.colonna / 3][val] = true;
    sol.valori_in_riga[sol.riga][val] = true;
    sol.valori_in_colonna[sol.colonna][val] = true;
}


void remove(Soluzione& sol) {
    int val = sol.mappa[sol.riga][sol.colonna];
    sol.mappa[sol.riga][sol.colonna] = 0;

    sol.valori_in_sottomatrice[sol.riga / 3][sol.colonna / 3][val] = false;
    sol.valori_in_riga[sol.riga][val] = false;
    sol.valori_in_colonna[sol.colonna][val] = false;
}


void incrementaCella(Soluzione& sol) {
    if(sol.colonna == 8) sol.riga++;
    sol.colonna = (sol.colonna + 1) % 9;
}

void decrementaCella(Soluzione& sol) {
    if(sol.colonna == 0) {
        sol.riga--;
        sol.colonna = 8;
    }
    else sol.colonna--;
}



