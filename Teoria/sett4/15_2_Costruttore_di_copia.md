# Costruttore di copia

Il *Costruttore di copia* Consente di costruire un oggetto come **copia** di un altro oggetto.
*(deep copy)*

```cpp
class MyClass{
public:
	int a, b;
	string c;

	// costruttori diversi
	MyClass(int x, int y, string s) {} 
	
	//costruttore di copia
	MyClass(const MyClass& x): a(x.a), b(x.b), c(x.c) {}
}
```

Se non viene definito viene fatta una copia superficiale (*shallow copy*)

```cpp
int main(){
	MyClass q;
	// inizializza q...


	// qua chiama il costruttore di copia
	MyClass z = q; // oppure z(q)
	// inizializzazione per copia

	z = q; // qui usa l'operatore '='
}
```

con classi semplici non si nota molto la differenza tra defirilo o no

se ad esempio la classe contiene al suo interno

___

il costruttore di copia viene automaticamente chiamato in casi come:

```cpp
void f(MyClass x){
	....
}

int main(){
	MyClass q;
	// inizializza q...

	f(q); // utilizza sempre il costruttore di copia

	z = q; // qui usa l'operatore '='
}

```

```cpp
class Esempio{
	string *ptr;
public:
	// costruttori
	Esempio(): ptr(new string) {};
	Esempio(const string& str): ptr(new string(str)) {};
	
	~Esempio() { delete ptr; };
	Esempio( const Esempio& x): ptr(new string(x.content())) {}

	const string& content() const { return *ptr; }

}

```
