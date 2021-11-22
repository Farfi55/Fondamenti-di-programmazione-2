# Alberi binari di ricerca 

ricerca in *O(log n)* quando l'albero è completo, pieno o approssimabile a *O(log n))* quando è bilanciato

`|3|5|7|9|15|18|22|`

```text
3
 \
  5
   \
    7
     \
      9
       \
        15
         \
          18
           \22
```

prendendo l'elemento a metà

```text
        9
      /   \
    5      18
   / \    /  \
  3   7  15  22
```

un primo metodo per aggiungere nuovi elementi all'albero è:

- aggiungere elemento sotto l'elemento corretto
- visita simmetrica per creare un array con i nodi dell'albero
- sort sull'array
- si ricrea l'albero usando l'array ordinato

questo approccio è poco efficente.



## coefficente di sbilanciamento per ogni nodo

tiene traccia per ogni la differenza di profondità tra figlio sinistro e figlio destro

```text
      32 (2)
      /  
    28 (1)
     \   
     30 (0)
```

```text
      30 (0)
    /  \
  28   32  
  (0)  (0)
```


un albero ha vantaggi sulle hashmap quando serve prendere valori in un *range* invece che singoli elementi



