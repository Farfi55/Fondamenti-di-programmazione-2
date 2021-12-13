# Golosa (greedy)

brute force *(provarle tutte)*

gli algoritmi che usano la tecnica golosa sono spesso approssimativi

per ogni stadio della scelta golosa:

- scelta golosa        <- problema di ottimalità
- aggiungi scelta alla sol.

Esempio: Cambio di un assegno

tagli: `500, 200, 100, 50, 20, 10, 5, 2, 1, 0.5, 0.2, 0.1, 0.5`
dove i tagli sono ordinati in modo decrescente

passo base: per quel taglio segli il numero di banconote da dare

```text
per ogni taglio:
    n_banconote = floor(V_assegno / taglio);
    residuo = V_assegno - (n_banconote * taglio);
```

```text
input: 
vector<float> Tagli

out:
T cambio {
    Valore
    n_banconote[]
    // dove n_banconote[0] = # banconote del taglio Tagli[0]
}
```

esempio dell'approssimazione

tagli: 5 4 2 1
assegno: 8

l'algoritmo darà come risultato

```text
 5 4 2 1
[1 0 1 1]

ma c'era una soluzione migliore, che non ha trovato:

 5 4 2 1
[0 2 0 0]
```

che mostra come l'algoritmo goloso ragioni passo per passo e senza una visione generale, ma risolvando il problema velocemente
