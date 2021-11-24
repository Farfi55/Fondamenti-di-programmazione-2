# Rappresentazione dei grafi

## Rappresentazione con matrice di adiacenza

Vector di puntatori
di grandezza n che contiene i nodi

Matrice di adiacenza n x n

|     | 0   | 1   | 2   | 3   | 4   | 5   |
| --- | --- | --- | --- | --- | --- | --- |
| 0   |     |     |     |     |     |     |
| 1   |     |     |     |     |     | T   |
| 2   |     |     |     | T   |     |     |
| 3   |     |     |     |     |     |     |
| 4   |     |     |     |     |     |     |
| 5   |     | T   |     |     |     |     |

pro:

- semplicità
- esistenza di un arco in accesso diretto *O(1)*
  - arco (1,5)

contro:

- la matrice di adiacenza occupa n*n byte, se il grafo è sparso c'è molto spreco
- Scorrere gli adiacenti in *O(n)*
- Spazio Occupato *O(n^2)

## Rappresentazione a liste di adiacenza

usiamo una lista di int per ogni nodo che tiene gli indici dei collegamenti

| nodo | lista adiacenze |
| ---- | --------------- |
| 0    |                 |
| 1    | `[5, .]`        |
| 2    | `[3, .]`        |
| 3    | `[2,4, .]`      |
| 4    |                 |
| 5    | `[1,.]`         |
| n-1  |                 |

#### pro:

- spazio occupato *O(m+n)*
  - sparso (m ordine di grandezza di n) -> *O(n)*
  - denso -> *O(n^2)*
- scorrere gli adiacenti *O(n adiacenti)*
  - sparso (in media) -> *O(1)*
  - denso -> *O(n)*

#### contro:

- esistenza di un arco:
  - arco(1,5)? -> scorrere la lista
  - denso -> *O(n)*
  - sparso -> *O(n adiacenti)*

## riepilogo

Quando il grafo è denso:
Rappresentazione con la matrice di adiacenza

Quando il grafo è sparso:
Rappresentazione a liste di adiacenza

___

```text
Grafo

GrafoOr  <- Grafo
GrafoNor <- Grafo

ListeAd
MatriceAd

GrafoOrL  <- GrafoOr,  ListeAd
GrafoNorL <- GrafoNor, ListeAd
GrafoOrM  <- GrafoOr,  MatriceAd
GrafoNorM <- GrafoNor, MatriceAd
```
