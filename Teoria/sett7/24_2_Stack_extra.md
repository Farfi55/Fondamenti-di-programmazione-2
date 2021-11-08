# Stack

## Stampa dello stack

output:

> 15 3 72 8

```cpp
void printStack(stack<int>& s) {
    if(s.empty()) return;

    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
}
```

```cpp
int main() {
    stack<int> s;
    s.push(15);
    s.push(3);
    s.push(72);
    s.push(8);

    printStack(s);

    cout << "seconda chiamata\n\n";
    printStack(s);
}
```

### ESERCIZI

e_palindroma con stack

*(nella prossima lezione)*

classe matrice

classe matrice_simmetrica
