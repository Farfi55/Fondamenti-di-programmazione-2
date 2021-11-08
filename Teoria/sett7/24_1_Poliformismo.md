# Poliformismo

```cpp
class Polygon {
protected:
    int width, height;
public:
    void set_values(int w, int h) { 
        width = w; 
        height = h;
    }
}
```

```cpp
class Rectangle : public Polygon{
public:
    int area() { return width * height; }
}
```

```cpp
class Triangle : public Polygon{
public:
    int area() { return width * height / 2; }
}
```

abbiamo ogni volta creato un metodo `area()` diverso

```cpp
int main() {
    Rectangle rect;
    Triangle trig;

    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trig;

    ppoly1-> set_values(4, 5);
    ppoly2-> set_values(4, 5);
}
```

| porzione di memoria | contenuto | Appartiene a  |
| ------------------- | --------- | ------------- |
| width               | 4         | Polygon       |
| height              | 5         | Polygon       |
| **area()**          |           | **Rectangle** |

## Overriding

se vado a cambiare leggermente la classe polygon

```cpp
class Polygon {
    ...
    virtual int area() { return 0; }
}
```

con `virtual` vado a dire che le classi che derivano da questa classe possono sovrascrivere il funzionamento di questa funzione  
quello che effettivamente accade è che `int Polygon::area()` andrà a chiamare la funzione area della classe derivata;

ora posso fare

```cpp
int main() {
    Rectangle rect;
    Triangle trig;
    Polygon poly;

    Polygon* ppoly1 = &rect;
    Polygon* ppoly2 = &trig;
    Polygon* ppoly3 = &poly;

    ppoly1->set_values(4, 5);
    ppoly2->set_values(4, 5);
    ppoly3->set_values(4, 5);

    // Polygon::area() -> Rectangle::area() -> 20
    cout << ppoly1->area() << endl; 

    // Polygon::area() -> Triangle::area() -> 10
    cout << ppoly2->area() << endl;
    
    // Polygon::area() -> 0
    cout << ppoly3->area() << endl;

}
```

con `virtual` non è *obbligatorio* andare a sovrascrivere il comportamento della funzione

abbiamo dovuto mettere `virtual int area() { return 0; }` per dare visibilità alla funzione

## Abstract

I tipi di dati **astratti** non posso essere definiti da se, ma servono come blocco di costruzione per i tipi derivanti

es: non puoi disegnare un poligono, perchè non sai quanti lati ha ad esempio

se andassimo a scrivere

```cpp
class Polygon {
    ...
    // VIRTUALE PURA
    // -> classe astratta
    virtual int area() = 0;
}
```

avendo una funzione virtuale pura, non possiamo più andare a dichiarare oggetti della classe base

```cpp
Polygon poly; // ERRORE
Polygon *pp1 = &rect; // va bene
Polygon *pp2 = &rect; // va bene
```

___

```cpp
class Polygon {
    ...
    virtual int area() = 0;
    void printArea() {cout << this->area(); }
}
```

quando chiami la funzione area su un oggetto puntatore di `printArea` il puntatore this punta alla classe base, accede a `Polygon::area()` che reinderizza sul giusto override della funzione

Dichiarare un override di `area` nelle classi derivate diventa obligatorio

```cpp
Polygon *ppoly1 = &rect;

// Polygon::printArea() { this->area(); } 
// -> Polygon::area() 
// -> Rectangle::area()
// -> 20
ppoly1->printArea();
```

**`ppoly1`**

| porzione di memoria | Appartiene a  |
| ------------------- | ------------- |
| width               | Polygon       |
| height              | Polygon       |
| area() = 0          | **Polygon**   |
| area()              | **Rectangle** |

### costruttore

```cpp
class Polygon{
    ...
public:
    ...
    Polygon(int a, int b): width(a), height(b) {}
};
```

```cpp
class Rectangle : public Polygon {
public:
    int area() ...
    Rectangle(int a, int b): Polygon(a,b) {}
};
```

```cpp
class Triangle : public Polygon {
public:
    int area() ...
    Triangle(int a, int b): Polygon(a,b) {}
};
```

```cpp
int main() {
    Polygon *ppoly1 = new Rectangle(4, 5);
    Polygon *ppoly2 = new Triangle(4, 5);
    ppoly1->printArea();
    ppoly2->printArea();
    // sa che è un Rectangle sotto sotto, elimina l'intero Rettangolo
    delete ppoly1; 
    delete ppoly2; 
}
```
