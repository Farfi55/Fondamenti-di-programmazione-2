# Friend

```cpp
class Rectangle{
	int width, height;
	....
}

Rectangle duplicate(const Rectangle& param){

	Rectangle rec;

	// ERRORE! width è un membro privato, non accessibile da questo contesto esterno
	rec.width = param.width*2;	
	rec.height = param.height*2;
	return rec;
}
```

### usando `friend` su un metodo

```cpp
class Rectangle{
	int width, height;
	....

	// dichiariamo amica la funzione
	// dandogli i privilegi di accedere ai membri privati dell'oggetto
	friend Rectangle duplicate(const Rectangle&);
}

Rectangle duplicate(const Rectangle& param){

	Rectangle rec;

	// Tutto ok!
	rec.width = param.width*2;	
	rec.height = param.height*2;
	return rec;
}
```

### usando `friend` su un'altra classe

```cpp
class Rectangle{
	int width, height;
	...

public:
	void convert(Square a);

	...
}

class Square{

friend class Rectangle;

private:
	int side;
public:
	Square(int a): side(a) {}


}

void Rectangle::convert(Square a){
	// usando friend, possiamo accedere al membro privato di Square size
	width = a.side;
	height = a.side;
}

int main(){
	Rectangle rect;
	Square sqr(4);
	rect.convert(sqr);

	cout << rect.area(); // 4*4 = 16

}


```
