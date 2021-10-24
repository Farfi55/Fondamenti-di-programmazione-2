
# Complessità di un algoritmo

|                    |                                                     |
| ------------------ | --------------------------------------------------- |
| **spazio**         | Complessità spaziale (lo spazio aggiunto all'input) |
| **velocità (sec)** | Complessità temporale                               |

## Modello di costo

- dimensione dell'input
- costo unitario delle operazioni di base

$n$ = dim. dell'input
1 operazione = $10^{-6}\sec$
| nome   | num operazioni | n = 10         | n = 10000 | n = 10^6       |
| ------ | :------------: | -------------- | --------- | -------------- |
| algo 1 |       n        | $10^{-5}\sec$  | 10^-2sec  | 1sec           |
| algo 2 |      n^2       | $0.1\sec$      | 100sec    | 10^6sec ~ 12gg |
| algo 3 |    nlog(n)     | $310^{-6}\sec$ | 0.13sec   | 19 sec         |

___

## Dim dell'input

da cosa dipende il n. di op. da eseguire

fib(n)  - 1 var
 ^ - il contenuto è quello che conta
dim input

- costo unitario:
 costo = 1
  - lettura / scrittura       `(cin, cout)`
  - assegnamento, op. aritmetiche predefinite, return
  - accesso ad un elemento di un array  `(a[i]=a[i+1])`
  - valutazione di espressioni booleane  `((x>100)&&(y!=45)||...)`

```cpp
int i = 1;  // 1 assegnamento
while(i<=n) // n+1 confronti
  i=i+1;  // 1*n 1 assegnamento n volte
 // f(n):   2n+2
```

| nome  | f(x)            | n --> inf  |
| ----- | --------------- | ---------- |
| f1(n) | 2n + 3          | --> n      |
| f2(n) | 4n^4 + 3n^2 + 2 | --> n^4    |
| f3(n) | 4log(n) + 3     | --> log(n) |

## Complessità Asintotica

- notazione $O$
- notazione s2

$f(n) \in O(g(n))$  se  $\exists  c,n_0 > 0$   t.c.
$\forall  n > n0$  
$0 \le f(n) \le c \cdot g(n)$$

### Alcuni andamenti

- $O(1)$ costante
- $O(\log(n))$ logaritmico
- $O(n)$ lineare
- $O(nlog(n))$
- $O(n^2)$ quadratico
- $O(n^3)$ cubico
- $O(n^{4^+})$ polinomiale
- $O(2^n)$ esponenziale

"in termini di costanti" (per n piccoli)
___

istruzioni di costo unitario O(1)
blocchi di istruzioni

$f_1 \rarr O(g_1) +$  
$f_2 \rarr O(g_2) +$  
$f_3 \rarr O(g_3) +$  
$f_4 \rarr O(g_4) =$  
$\max(g_1, g_2, g_3, g_4)$

___

```cpp
if (cond)    // f_cond + f_if   |
    {blocco if}              // | max
else         // f_cond + f_else |
    {blocco else}
```

## casi

- caso peggiore ( il più importante )
- caso migliore ( # minimo op per risultato )
<!-- - caso medio -->

## cicli

```cpp
while(cond){    
 /*corpo while*/   
}
```

$f_{cond}  =  k iter$  
$f_{corpo} = k (f_{cond} + f_{corpo})$
___

```cpp
for(init, cond, agg){
  /*corpo for*/
}
```

## chiamata di funzioni

```cpp
ret_type f(param_type param){
  //corpo;
  return;
}
```

- Costo passaggio parametro:  
  - se passo per valore(senza `const`) devo fare una copia, può diventare costoso
- costo della `return`
- costo del corpo

___

```cpp
int fib(int n){     // O(1)
  int f, f1 = 0, f2 = 1;  // O(1)
 
   //caso migliore O(1)
   //caso peggiore O(n)
  if( n==0 || n == 1) return n;  
  else
    for (int i = 0; i < n; i++)
    {   
      f = f1 + f2; // O(1) n volte
      f2 = f1;  //
      f1 = f;   // 1*n --> O(n) 
    }
  return f; // O(1)
}
```

```cpp
//    m
//  *****
//n *****
//  *****
         
for (int i = 0; i < n; i++){ //  |
  for (int j = 0; j < m; j++) //|m |n
    cout << "*"; // 1   |  |  
  cout << endl;  // 1   |
}    // O(n*m)

```

```cpp
//  *
//n **
//  ***
//  ****
//    n
         
for (int i = 0; i < n; i++){
 for (int j = 0; j <= i; j++)
  cout << "*";    
 cout << endl; 
}    

// 1 + 2 + 3 + ... + n
// f_costo = (n * (n+1)) / 2
// f_costo ~ n^2
// O(n^2)
```
