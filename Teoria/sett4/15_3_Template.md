# Template

I template ci permettono di definire una classe una volta e farla funzionare per più tipi

```cpp
template<T>
class mypair{
	T values[2];
public:

	mypair(T first, T second){
		values[0] = first;
		values[1] = second;
	}

	T getMax();
};
```

```cpp
template<class T>
T mypair<T>::getMax(){
	if(values[0] > values[1]) return values[0];
	else return values[1];
}
```

```cpp
int main(){
	mypair<int> myobject(114, 36);
	mypair<double> myfloats(2.56, 3.14);

	cout << myobject.getMax() << endl;
	cout << myfloats.getMax() << endl;

}
```

questo modo di creare classi è estremamento potente perchè ci permette di scrivere una volta la classe e poterlo utilizzare genericamente con tanti tipi.  

**Attenzione** con i tipi user-defined non sappiamo se il template funzionerà,  
ad esempio:

```cpp
int main(){
	mypair<Rectangle> myrectangles = ....;
	cout << myrectangles.getMax();
	// comportamento non definito, perchè la classe Rectangle potrebbe non aver implementato l'operatore '>' ad esempio
}
```

___

## Classi con più tipi template

### dichiarazione

```cpp
template<class T1, class T2>

class Pair{
	T1 first;
	T2 second;
public: 
	Pair(T1 f, T2 s);
	T1 getFirts() const { return first; }
	T2 getSecond() const;
	void setFirts(T1 f) { first = f; }
	void setSecond(T2)
};
```

### implementazione

```cpp
Template<class T1, class T2>
Pair<T1, T2>::Pair(T1 f, T2 s){
	first = f;
	second = s;
	//oppure usando la preinizializzazione
}


Template<class T1, class T2>
T2 Pair<T1, T2>::getSecond() const 
{ 
	return second;
}

Template<class T1, class T2>
void Pair<T1, T2>::setSecond(T2 s) const 
{ 
	second = s;
}
```

### utilizzo

```cpp
int main(){
	Pair<int, char> p1(1,'a'); 
	Pair<string, string> p2("hello","world"); 

	cout << p1.getSecond() << endl;
	cout << p2.getFirst() << endl;
}
```
