#include <iostream>


void reset(int &i); // dichiariamo ci sarà una funzione reset


int main ()
{
    int j = 42;
    reset(j);   // scrivere reset(&j) modifica direttamente l'indirizzo di j, ERRORE
                // reset(*j) cerca di accedere al valore in posizione 42, ERRORE
    std::cout << j << std::endl;
}


void reset (int &i){ // la definisco quando voglio
    i = 0;
    return;
}