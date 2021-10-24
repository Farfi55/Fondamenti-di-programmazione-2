# distruttore

Viene chiamato quando una variabile finisce la sua vita  
come ad esempio alla fine di una funzione

quando facciamo uso della memoria dinamica all'interno della classe diventa fonfdamentale andare a definire un distruttore che vada a liberare quella parte di memoria allocata una volta che l'oggetto venga distrutto

```cpp
class Esempio{

	string * ptr;
public:
	//costruttori
	Esempio() : ptr(new string) {};
	Esempio(const string& str) : ptr(new string(str)) {};

	//distruttore
	~Esempio() { delete ptr; };
...
}
```

lo rivedremo più avanti
