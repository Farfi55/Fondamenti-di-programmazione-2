# Classi (2)

[Indice](../0_INDEX.md)

- [Classi (2)](#classi-2)
	- [differenza tra struct e class](#differenza-tra-struct-e-class)
	- [Puntatori a classi](#puntatori-a-classi)
		- [utilizzo dei puntatori](#utilizzo-dei-puntatori)
	- [Overloading degli operatori](#overloading-degli-operatori)
		- [Passaggio di parametri](#passaggio-di-parametri)
	- [Operatori](#operatori)
		- [Operatori unari](#operatori-unari)
		- [Operatori Binari](#operatori-binari)
	- [Overloading degli operatori come fun. non membro esterno](#overloading-degli-operatori-come-fun-non-membro-esterno)
	- [This](#this)
	- [Funzioni membro Costanti](#funzioni-membro-costanti)
	- [Modi diversi di usare const](#modi-diversi-di-usare-const)
	- [Membri Statici](#membri-statici)
  
___

<br>

```cpp
class Rectangle{
	int width, height;
public:
	Rectangle(int, int);
	int area();
};
```

## differenza tra struct e class

di default lo specificatore di accesso è:  

- `public` per le struct  
- `private` per le classi  

di solito le struct vengono usati per modelli poco complessi

## Puntatori a classi

```cpp
Rectangle* rect;
```

```cpp
int main(){
	Rectangle obj(3,4);
	Rectangle *foo, *bar, *baz;

	// inizializzo uno di questi puntatori
	// con l'indirizzo già creato in precedenza
	// foo punta a obj
	foo = &obj;

	// costruisco un nuovo oggetto di tipo rettangolo
	// 
	bar = new Rectangle(4,6);

	// definiamo un array di 2 elementi di tipo rettanglolo
	// ATTENZIONE! Viene chiamato automaticamente il costruttore di default
	baz = new Rectangle[2];
	delete [] baz;

	// usiamo l'assegnazione 
	baz = new Rectangle[2] { {2,5}, {3,6} };

	cout << obj.area() << endl; // obj è già oggetto
	
	// per accedere alla funzione area dell'oggetto puntato da foo,
	// dobbiamo usare la freccia 
	cout << foo->area() << endl; 

	// anche nel caso di bar bisogna usare la freccia
	cout << bar->area() << endl; 
	
	// ATTENZIONE! baz[0] è un oggetto di tipo Rettagolo
	// quindi non abbiamo bisogno della freccia,
	// ma basta un punto . 
	cout << baz[0].area() << endl;  	
	cout << baz[1].area() << endl; 	
}
```

### utilizzo dei puntatori

```cpp
// x : variabile

*x; // puntato da x
&x; // indirizzo di x

x.y; // membro y di x
x->y; // membro y dell'oggetto puntato da x
(*x).y; // membro y dell'oggetto puntato da x

x[i]; // i-esimo *oggetto* puntato da x
```

## Overloading degli operatori

```cpp
int main(){
	Rectangle obj(3,4);
	Rectangle a(5,6), b(6,7);

	// Messsaggio di errore, comportamento indefinito
	a = b + obj; // ???

```

come eseguire l'overloading dell'operatore:

`TIPO operator simboloOperatore(parametri){corpo...};`

```cpp
// comportamento aspettato:
// (x1,y1) + 
// (x2,y2) = 
// (x1+x2, y1+y2) 

class CVector{
public x,y;
	Cvector();
	Cvector(int o, int b): x(o), y(b) { };

	CVector operator+ (const CVector&);

	// è buona norma definirla per le classi
	CVector operator= (const CVector&);

};

// definizione esterna
// tipo   risolutore di    parametri
// ret.   visibilità
CVector CVector::operator+ (const CVector& param){
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;	
	return temp;
}

CVector CVector::operator= (const CVector& param){
	x = param.x;
	y = param.y;
	return *this;
}
```

```cpp
CVector p1(3,4), p2(5,6), p3;

p3 = p1 + p2;

// CVector temp (3+5, 4+6)
// temp.x = 8
// temp.y = 10

// p3 = temp
// p3.x = temp.x
// p3.y = temp.y

// ATTENZIONE! senza la definizione di operator=
// l'assegnazione potrebbe funzionare ma facendo una copia
// di tutti i dati dell'oggetto, BAD PRACTICE

// GOOD PRACTICE definire esplicitamente 
// l'overloading dell'operatore =
```

<br>

### Passaggio di parametri

```cpp
// passaggio per valore (copia)
// ! può diventare molto costoso
void fun(CVector param); 

//passaggio per riferimento (indirizzo)
void fun(CVector &param); 

// passaggio per riferimento costante 
// (indirizzo, oggetto invariabile)
void fun(const CVector &param);
```

<br>
___

## Operatori

`@` dove `@` è un operatore generico  

### Operatori unari

esempio: `++a` oppure `!a`  
per definire questi operatori:  

```cpp
A::operator@()
```

### Operatori Binari

```cpp
>> A::operator@(B)
// a@b 
```  

## Overloading degli operatori come fun. non membro esterno

in alcuni casi è l'unico modo per definire alcune funzionalità  
questo modo ha un problema, se x e y fossero private, non potremmo andare ad assegnare un nuovo valore di x e y

```cpp
CVector operator+ (const CVector &lhs, const CVector &rhs){
	CVector temp;
	temp.x = lhs.x + rhs.x;
	temp.y = lhs.y + rhs.y;
	return temp;
}
```

___

## This

`this` è il puntatore all'oggetto in cui la funzione membro viene eseguita  

```cpp
class Dummy{
public:
	bool isItMe(Dummy & param){
		if (param == this)
			return true;
		else
			return false;
	}
}

int main(){
	Dummy a;
	Dummy *b = &a;

	if(b->isItMe(a))
		cout << "Sono io!";

	return 0;
}
```

## Funzioni membro Costanti  

```cpp
class MyClass{
public:
	int x;
	MyClass (int val): x(val) { };
	int get () { return x; }
}

int main(){
	const MyClass foo(10);
	// ! ERRORE, non posso modificare l'oggetto
	foo.x = 20;

	cout << foo.x << endl; // ok
	
	cout << foo.get() << endl; // NO!
}
```

Per dichiarare che la funzione non andrà a modificare i membri della classe dobbiamo aggiungere la keyword
`const` dopo dei parametri

```cpp
class MyClass{
public:
	int x;
	MyClass (int val): x(val) { };
	int get () const { return x; }
}

// in main
	cout << foo.get() << endl; // ok
```

## Modi diversi di usare const

```cpp
int get() const { ... }

// get è una funzione membro generica che restituisce un riferimento costante
// ! ATTENZIONE la funzione membro non è costante
const int & get() { ... }

//è una funzione membro COSTANTE che restituisce un rif. const
const int& get() const { ... }
```

un oggetto const possono chiamare solo funzioni costanti,  
gli oggetti non-const possono chiamare tutti i tipi di funzioni  

Se scrivo

```cpp
class MyClass{
public:
	int x;
	MyClass (int val): x(val) { };
	int get () const { return x; } // #1
	int & get () { return x; } // #2
}
```

Se a chiamare `get()` sarà un oggetto const verrà chiamato `get() #1`  
altrimenti verrà utilizzato `get() #2`

```cpp
int main(){
	MyClass foo(10);
	const MyClass bar(20);

	foo.get() = 15;
	bar.get() = 25; // ! ERRORE

	cout << foo.get() << endl; // 15
	cout << bar.get() << endl; // 20
}
```

## Membri Statici

```cpp
class Dummy{
public:
	static int n;

	Dummy(){
		n++;
	}
}
// per inizializzare una variabile static
Dummy::n = 0;
```

`n` conterà il numero di oggetti Dummy creati  

```cpp
int main(){
	Dummy a;
	Dummy b[5];

	cout << a.n << endl; // stampa 6 
	
	Dummy * c = new Dummy;
	
	cout << Dummy::n << endl; // stampa 7
	delete c;

	cout << Dummy::n << endl; // stampa 7

}
```
