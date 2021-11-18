# 15/11/2021

## Strutture dati: alberi

Gli alberi ci permettono di rappresentare le strutture dati gerarchiche (o gerarchie). É formato da:
- Nodi: un solo arco entrante, n archi uscenti. 5 tipi:
  - Padre: nodo di partenza dell'arco
  - Figlio: nodo di fine dell'arco.
  - Radice: nodo di partenza, nessun arco entrante
  - Foglie: nodi terminali, non hanno figli
  - Fratelli: nodi "figli" dello stesso "padre"
- Archi: relazioni fra nodi padre-figlio, direzionati
- Livelli:
  - Si parte dal livello 1, ovvero il nodo radice
  - Livello dei figli: livello del padre + 1
  - Profondità di un albero: determinato dal livello max.



### Diversi tipi di albero:

- Albero generico: un normale albero, n non fissato.
- Albero n_ario: albero con n fissato, numero massimo di figli per nodo pari ad n.
- Albero binario: n = 2, max 2 figli.
  - Nodi: se profondità = k:
    - min = k
    - max = 2^k.
  - Profonditá: se numero nodi = n: 
     - min = O(logn)
     - max = O(n).
- Albero nullo: basilarmente vuoto.
- Albero degenere: ogni padre ha esattamente un figlio
- Albero completo: in tutti i livelli tranne l'ultimo, tutti i nodi hanno il numero massimo di figli.
- Albero bilanciato: per ogni nodo n, | PNS - PND | < 1. Leggenda:
  - PNS: Numero di nodi nel sottoalbero a sx
  - PND: Numero di nodi nel sottoalbero a dx



### Percorso "radice - nodo scelto":

- Soluzione migliore: partire dal nodo scelto andando verso la radice. Si sfrutta il fatto che il nodo ha, ogni volta, un padre, fino ad arrivare alla radice.



### Rappresentazioni alberi:

- Rappresentazioni indicizzate:
  - Vettore dei padri: usiamo un array in cui ciascuna cella contiene una coppia (info, parent)
    - Pro:
      - Molto semplice da utilizzare
      - Permette la rappresentazione di alberi generici
      - Consente l'aggiunta/rimozione di nodi molto facilmente
      - Ricerca dei padri molto semplice
    - Contro:
      - Ordine a caso, per trovare un nodo bisognerà scandire (potenzialmente) tutto l'array
  - Vettore posizionale: si utilizzano, nell'array, delle celle per identificare radice, figli, figli dei figli etc.
    - Sono limitato agli alberi d-ari, ovvero alberi con numero max di figli
     - Leggenda: d: numero max di figli, v: posizione del nodo nell'array
    - Pro:
      - Accesso ai figli con costo O(1), formula: P[d*v+i], i compreso fra 0 e d-1
      - Accesso al padre con costo O(1), formula: int(v/d)
    - Contro:
      - Dato K come profondità max, devo allocare un array di dimensione K, creando potenziali sprechi di spazio se l'albero non é bilanciato e/o non riesco a prevedere la profondità max.
- Rappresentazioni collegate: 
  - Puntatori ai figli: ogni nodo conterrà un puntatore a tutti i suoi figli, numero max di figli fissato.
    - Pro: accesso diretto ai figli
  - Liste di puntatori ai figli: utile quando non si conosce il numero massimo di figli. Ogni nodo contiene una lista avente puntatori a tutti i figli.
    - Contro: perdo l'accesso diretto ai figli
  - Rappresentazione "primo figlio - fratello": ogni nodo "figlio" ha un puntatore al suo "fratello".
