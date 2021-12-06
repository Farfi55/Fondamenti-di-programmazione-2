# backtraking

sono di fatto esponenziali, si costruisce la soluzione del problema un pezzo alla volta
si costruiscono delle prove parziali che quando non funzionano tornano indietro cambiando la scelta fatta

esempio classico di backtracking:

### Colorabilità di una mappa *(n-col)*

quando si hanno 3 colori viene chiamato 3-col

```text
   1
_______
 2 | 6
_______
 3 | 5 
_______
   4
```

l'algoritmo cerca di assegnare il primo colore disponibile a ogni nazione, quando questo giunge ad una soluzione inammissibile, torna indietro provando la prossima scelta.
Rispetto al brute force ci permette di risparmiare molto tempo non andando a evalutare le soluzioni derivate da scelte inammissibili.

l'algoritmo si pone bene per problemi decisionali e per problemi di ottimizzazione


in questo problema:

modello i confini come una matrice (tipo grafo)

quindi, struttura input:

```text
  1 2 3 4 5 6
1   T       T
2 T   T     T
3   T   T T
4     T   T
5     T T   T
6 T T     T
```

struttura soluzioni:
array o vector con le scelte in ordine a come sono state fatte

definire il dominio della sotto-sol:

x in [*MIN_VAL*, *MAX_VAL*]

## Requisiti

- Spazio soluzioni finito
- Soluzione rappresentabile come sequenza di soluzioni parziali
- La Dim (massima) della soluzione è nota a priori
- Il valore di ciascuna sotto-soluzione appartiene ad un dominio finito
  
```text
    minval  maxval 
S_0 [?,..., , , ]
...
S_i [x,...,?, , ]
...
S_n [x,x,x,x,x,?]

```

```text
bool solve(sol) {
    x = MIN_VAL
    while(x <= MAX_VAL) {
        if(canAdd(x, sol)) {
            add(x, sol)
            if(isComplete(sol)) 
                return true
            else if(solve(sol))
                return true
            else {
                remove(x,sol)
                x = next(x)
            }
        }
        else
            x = next(x)
    }
    return false
}
```

nel caso del problema della colorabilità

MODELLO PROBLEMA

Grafo *G* o Matrice di bool

SOL:

Lista o vector

Dominio sottosol

MIN_VAL rosso, verde  
MAX_VAL blu

enum colors = {Rosso = 1, Verde, Blu},
MIN_VAL = 1
MAX_VAL = 3

```cpp
void add(x, sol) { sol.push_back(x); }
void remove(x, sol) { sol.pop_back(x); }

bool isComplete(sol) {
    return G.n() == size(sol);
}

bool canAdd(x, sol) {
    int s = size(sol);
    for(int i = 0; i < s; i++) 
        if(G(i, s) && sol[i] == x) // se sono confinanti
            return false;
    return true;
}
```

una buona pratica potrebbe essere quella di definire una struct per la soluzione

```text
struct TSol {
    - modello del problema
    - soluzione
}
```
