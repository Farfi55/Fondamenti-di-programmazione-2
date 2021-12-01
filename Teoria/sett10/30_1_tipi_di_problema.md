# Tipi di problemi

- Decisionali *(si o no)*
- Det. una soluzione *(se esiste)*
- Det. la sol. migliore *(ottimizzazione)*
  - { soluzioni esatte
  - { soluzioni approssimate

```text
max F = SUM(i=1..n) x_i * V(x_1 ... x_n)

con vincoli 
    C(x_1 ... x_n ) <= Cmax
    0 <= x_i <= q_i
```

```text
min F = SUM(i=1..n) x_i * V(x_1 ... x_n)

con vincoli 
    C(x_1 ... x_n ) >= Vmin
    0 <= x_i <= q_i
```
