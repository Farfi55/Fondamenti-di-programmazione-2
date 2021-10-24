//una famiglia S di insiemi di interi positivi può ossere rappresentato da una sequenza di interi seq(S),
// terminata da -1, ed in cui  ongi insieme della famiglia sia separato dal successivo da uno 0
//
// {7,3},{5,1,7,4},{2},{},{3,9}} dalla seq: 7 3 0 5 1 7 4 0 2 0 0 3 9 0 -1
//
//quesito 1. si scriva un programma c++ che letta una tale sequenza se1(S):
//1. fornisca in uscita la cardinalità della famiglia (cioè il numero degli insiemi che essa contiene); 
// nell'esempio, il programma dovrebbe stamapare 5
//2. fornisca in uscita la cardinalità massima degli insiemi della famiglia; nell'esempio, dovrebbe
// stampare 4

#include <iostream>

using namespace std;

int main(){

    int val;
    int n_insiemi = 0, card = 0, card_max = 0;
    
    cout << "Inserisci la sequenza: " << endl;
    cin >> val;
    while (val != -1)
    {
        
        if(val == 0){
            n_insiemi++;
            if(card > card_max){
                card_max = card;
            }
            card = 0; 
        }
        else{
            card++;
        }

        cin >> val;
    }
    
    cout << "Cardinalita' della famiglia: " << n_insiemi << endl;
    cout << "Cardinalita' massima degli insiemi: " << card_max << endl;


    return 0;
}