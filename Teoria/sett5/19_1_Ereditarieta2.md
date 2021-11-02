# Ereditarietà (2)

## Cosa viene ereditato dalla classe base

tutto tranne:

- I costruttori e il distruttore
- I membri dell'operatore di assegnazione
- Le friendship
- I membri privati

quando la classe derivata viene creata, viene chiamato in automatico il costruttore della classe di base.

Se non viene specificato altrimenti, il costruttore della classe derivata chiamerà il **costruttore di default** della classe base.

## Esempio

```cpp
class Mother{
public: 
	Mother() { cout << "Mother: no parameters\n"; }
	Mother(int a) { cout << "Mother: int parameter\n"; }
}
```

```cpp
class Daughter : public Mother{
public:
	// NOTA: non viene esplicitamente chiamato il costruttore di Mother 
	Daughter(int a) { cout << "Daughter: int parameter\n"; }
}
```

```cpp
class Son : public Mother{
public:
	// NOTA: esplicitiamo la chiamata al costruttore con un parametro int
	Son(int a): Mother(a) 
	{ cout << "Son: int parameter\n"; }
}
```

```cpp
int main(){
	Daughter kelly(0);	// Mother: no parameters
						// Daughter: int parameter

	Son bud(0);			// Mother: int parameter
						// Son: int parameter
}
```

inoltre C++ permette l'utilizzo di Ereditarietà multipla, che non andremo a vedere nel corso perchè troppo complicato
