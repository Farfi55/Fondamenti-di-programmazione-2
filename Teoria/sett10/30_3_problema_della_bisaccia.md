# Knapsack 0-1 (bisaccia)

```text
max F = sum(i=1..n) x_i * v_i
    sum(i=1..n) c_i * x_i <= Cmax
    x_i in {0, 1}
```

ordinare in base a V_i/c_i

scelta golosa: costo c_i <= CostoResiduo ?

```text
Cmax = 50
valore    costo   Vspec  prendo  residuo
v1 = 60   c1= 10   6      X     50
v2 = 100  c2= 20   5      X     40
v3 = 120  c3= 30   4      -     20

-> 160

non è ottima, potevo prendere {0, 1, 1}

esiste un unico v_i > ValoreSol -> si mette quello nella bisaccia
```

implementazione

```cpp
#include <algorithm>

struct Toggetto { int costo; int valore; }

bool greaterThan(Toggetto o1, Toggetto o2){
    return (o1.valore / o1.costo) > (o2.valore / o2.costo);
}

vector<bool> sKnapsack_01(vector<Toggetto>& oggetti, int Cmax) {
    int n = iggetti.size();
    sort(oggetti.begin(), oggetti.end(), greaterThan);
    vector<bool> sol(n, false);
    int Cspeso = 0;
    for(int i = 0; i < n && Cspeso <= CMax; i++) {
        if((Cspeso + oggetti[i].costo) <= Cmax){
            sol[i] = true; 
            Cspeso -= oggetti[i].costo;
        }
    }
    return sol;
}
```
