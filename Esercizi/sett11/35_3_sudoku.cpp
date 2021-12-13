//10-12-2021 10:29
#include <iostream>
#include <vector>
#include <array>

using namespace std;

// TODO FINIRE

struct Soluzione
{
    uint8_t mappa[9][9];
    uint8_t rigaCorrente;
    uint8_t colonnaCorrente;


    // dove l' i-esimo elemento dell'array più interno rappresente se l'elemento i è presente

    // nella riga indicata dall'array esterno
    bool elementi_in_riga[9][9];

    // nella colonna indicata dall'array esterno
    bool elementi_in_colonna[9][9];

    // nella sottomatrice (i,j)
    bool elementi_in_sottomatrice[3][3][9];


    Soluzione(uint8_t m[9][9]) : rigaCorrente(0), colonnaCorrente(0) {
        for(uint8_t i = 0; i < 9; i++)
            for(uint8_t j = 0; j < 9; j++) {
                uint8_t x = m[i][j];
                mappa[i][j] = x;
                elementi_in_riga[i][x] = (x != 0);
                elementi_in_colonna[j][x] = (x != 0);
                elementi_in_sottomatrice[i / 3][j / 3][x] = (x != 0);

            }
    }
};

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
        cout "> ";
        cin >> riga;
        if(riga == -1)
            break;

        cin >> colonna >> valore;

        mappa[riga][colonna] = valore;
        cout << "inserita (" << riga << ", " << colonna << "): " << valore << endl;


    }
    stampaMappa(mappa);


    Soluzione s(mappa);

    if(solve(s)) {
        cout << "trovata soluzione\n";
        stampaMappa(s.mappa);
    }



    return 0;
}


void stampaMappa(int mappa[9][9]) {
    // ... copiare dal prof

}

bool solve(Soluzione& soluzione) {
    // la posizione corrente ha già un valore 
    if(soluzione.rigaCorrente < 9 && soluzione.colonnaCorrente < 9 &&
        soluzione.mappa[soluzione.rigaCorrente][soluzione.colonnaCorrente] != 0) {
        incrementaCella(soluzione);

        if(solve(soluzione))
            return true;

        decrementaCella(soluzione);
        return false;
    }

    uint8_t val = 1;
    while(val <= 9) {
        if(canAdd(val, soluzione)) {
            add(soluzione, val);

            if(isComplete(soluzione)) return true;

            if(solve(soluzione)) return true;

            remove(soluzione);
        }
        val++;
    }
    return false;
}


bool isComplete(const Soluzione& sol);
bool canAdd(uint8_t val, const Soluzione& sol);
