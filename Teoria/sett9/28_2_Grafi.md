# Grafi

`G = <N, A>`

dove `N`: Nodi *(vertices, nodes)*
`A`: Archi *(edges)*


esempi applicativi di grafi:

- Città e strade che le collegano
- Rete di computer


i grafi si dividono in:

- Orientati
- Non orientati

## Orientati

un arco definito come (1, 3) va solo dal nodo 1 al 3, ma non dal 3 all'1

es: strade a senso unico

## Non Orientati

Un arco definisce un collegamento adirezionale

es: strade a doppio senso

___

Un altro modo per classificare u grafi e se gli archi sono:

- Pesati (info sugli archi)
- Non pesati

___

alcune proprietà:

`n` nodi
`m` archi 


ordinato:
`m` min: 0
`m` max: n(n-1) = (n^2)

non ordinato:
`m` min: 0
`m` max: (n(n-1))/2 = (n^2)


Grafo Denso n. archi O(n^2)
Grafo Sparso n. archi O(n^2)

Cammino: sequenza di archi

- semplice
- ciclo (cammino che torna su un nodo dello stesso)

Grado di un nodo:

- archi in entrata/uscita per grafi orientati


Grafo non orientato è connesso


### Chiusura transitiva di un grafo orientato

<!-- rendo espicito con un arco il fatto che quella coppia di nodi è raggiungibile con una serie di archi-->

creo degli archi che collegano direttamente nodi che sono comunque collegati seguendo un cammino
