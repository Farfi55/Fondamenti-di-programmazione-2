# bisaccia dinamica

S(i, w);

n oggettu i

* $v_i$ valore
* $c_i$ costo

$i \in (1 \dots n)$
$0 <= w <= W$

risolvi usando $\{o_1, \dots, o_i\}$ avendo a disposizione $W$

Problema originario $S(n, W)$
problemi banali:
$S(0, w)$ non ho oggetti da scegliere
$S(i, 0)$ non ho più spazio

se $S(i, w)$ non è banale
considero i ha $w_i$

* se $w_i > w$  --> $i$ non può essere selezionato
* se w_i <= w
  * $S(i-1, w - w_i)$   se lo prendo
  * $S(i-1, w)$         se non lo prendo
  scelgo l'opzione con valore maggiore

sia $v(i, w),   i = 0 \dots n, w = 0 \dot W$

* casi banali: $i = 0$ o $w = 0$
$v(i, 0) = 0$
$v(0, w) = 0$

* casi non banali
            { v(i - 1, w)   se  w_i > w
v(i, w)  =  {
            { max( v(i - i, w), max( v(i - i, w - w_i) + v_i)

soluzione $v(n, W)$

usando una matrice

```text

i\w 0   1   2   3   ... W
0   0   0   0   0   0   0
1   0
2   0
3   0
4   0                   SOL
```

Complessità $O(n \times W)$
