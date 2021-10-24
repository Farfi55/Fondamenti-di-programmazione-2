# File multipli

creiamo un nuovo file con estenzione `.h` che andrà a definire la classe  
in questo caso si chiamerà `pair.h`

visto che è una classe template c'è la necessità di implementare tutte le funzioni all'interno del file

mentre nelle classi normali si possono dividere definizione e implementazione

```cpp
#ifndef PAIR_H
#define PAIR_H

template<class T1, class T2>

class Pair{
	T1 first;
	T2 second;
public: 
	Pair(T1, T2);
	T1 getFirts() const;
	T2 getSecond() const;
	void setFirts(T1)
	void setSecond(T2)
}

#endif
```

creiamo un'altro file `main.cpp`

```cpp
#include <iostream>
#include <string>
#include "Pair.h"

using namespace std;

int main(){
	Pair<int, char> p1(1,'a'); 
	Pair<string, string> p2("hello","world"); 

	cout << p1.getSecond() << endl;
	cout << p2.getFirst() << endl;
}

```

`#include "Pair.h"` in questo caso cerca il file Pair.h nella directory del file corrente, se lo trova è *come* se lo copiasse all'interno del file

```cpp
#ifndef MYPAIR_H
#define MYPAIR_H

#endif
```

## Definizione e implementazione separati

`dummy.h` sarà il file per le definizioni

```cpp
#ifndef DUMMY_H
#include DUMMY_H

class Dummy{
	static int n;
public:
	Dummy();
	~Dummy();
	int howmany() const;
};

#endif

```

`dummy.cpp` verrà usato per le implementazioni

```cpp
#include "dummy.h"

Dummy::Dummy() {n++;}
Dummy::~Dummy() {n--;}

int Dummy::howMany() const {return n;}

```
