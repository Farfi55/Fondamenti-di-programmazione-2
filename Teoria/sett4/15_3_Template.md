



<!-- MANCA GRAN PARTE DELLA LEZIONE PER PROBLEMI TECNICI -->

<!-- TODO COMPLETARE -->

LEZIONE FINO ALLE 15:43

*

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
}

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



int main(){
	Pair<int, char> p1(1,'a'); 
	Pair<string, string> p2("hello","world"); 

	cout << p1.getSecond() << endl;
	cout << p2.getFirst() << endl;
}

```
