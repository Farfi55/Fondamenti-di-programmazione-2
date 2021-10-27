# Ereditarietà

a cosa serve:
Definire classi generali con comportamenti comuni  
per poi definire classi specifiche con comportamenti specifici

Polygon

`Rectangle` deriva da `(Polygon)`

- `area()`

`Triangle` deriva da `(Polygon)`

- `area()`

## Sintassi

```cpp
class DERIVED_CLASS : VISIBILITA BASE_CLASS
	(public)
	(protected)
	(private)
{
	...	
}
```

## Esempio

```cpp
class Polygon{
protected:
	int width, height;
public:
	void set_values(int a, int b){
		width = a;
		height = b;
	}
}
```

```cpp
class Rectangle : public Polygon {
public: 
	int area() { return width * height; }
	
}
```

```cpp
class Triagle : public Polygon {
public: 
	int area() { return (width * height) / 2; }	
}
```

## Accesso

| Accesso                      | public | protected | private |
| ---------------------------- | :----: | :-------: | :-----: |
| Membri della classe          |   SI   |    SI     |   SI    |
| Membri della classe derivata |   SI   |    SI     |   NO    |
| Non Membri                   |   SI   |    NO     |   NO    |

___

```cpp
int main(){
	Rectangle rect;
	Triangle trg;

	// chiama la definizione di set_values derivata da Polygon
	rect.set_values(4,5); 
	trg.set_values(4,5); 

	cout << rect.area() << endl; 	// 4 * 5     = 20 
	cout << trg.area() << endl; 	// 4 * 5 / 2 = 10

}
```
