template <class T>
int profondita( AlberoB<T> A )
{
	if (A.nullo()) return 0; 
	int p1=profondita(A.figlio(SIN));
	int p2=profondita(A.figlio(DES));
	return (p1>p2)? p1+1 : p2+1;
	
}


template <class T>
bool bilanciato(AlberoB<T> A )
{
	if (A.nullo()) return true;
	int p1=profondita(A.figlio(SIN));
	int p2=profondita(A.figlio(DES));
	bool b1=(abs(p1-p2)<=1);
	bool b2=bilanciato(A.figlio(SIN));
	bool b3=bilanciato(A.figlio(DES));
	
	return b1&&b2&&b3;
}


template <class T>
bool alberoBilanciatoProfondo( AlberoB<T> A, int& p )
{	if ( A.nullo() ) 
	{	p = 0;
		return true;
	}
	Card p1, p2;
	bool b1 = alberoBilanciatoProfondo(A.figlio(SIN),p1);
	bool b2 = alberoBilanciatoProfondo(A.figlio(DES),p2);
	p = max(p1,p2)+1;
	return b1 && b2 && (abs(p1-p2) <= 1);
}

template <class T> 
void visitaSimmetrica( const AlberoB<T>& A, list<T>& L )
{	if ( !A.nullo() )
	{	visitaSimmetrica(A.figlio(SIN),L); 	//**
		L.push_back(A.radice()); 		//**
		visitaSimmetrica(A.figlio(DES),L);	//**
	}
}


void visitaPerLivelli(const AlberoB<int>& a) {
    if (a.nullo())
        return;
    
    std::queue<AlberoBInt> q;
    q.push(a);
    
    while(!q.empty()) {
        AlberoBInt temp = q.front(); // q.front() restituisce l'oggetto in 
//testa alla coda SENZA RIMUOVERLO
        q.pop();			 // q.pop() rimuove l'oggetto in testa alla coda
        
// elaborare l'albero temp
        std::cout << temp.radice() << ' ';

        if (!temp.figlio(SIN).nullo())
            q.push(temp.figlio(SIN));
        if (!temp.figlio(DES).nullo())
            q.push(temp.figlio(DES));
    }
}



template <class T>
AlberoB<T> cerca(const AlberoB<T>& a, T v) {
    if (a.nullo() || a.radice() == v)
        return a;
    
    // a questo punto sono in un sottoalbero che non ha v come valore 
//informativo e non è nullo
    AlberoB<T> temp = cerca(a.figlio(SIN), v);
    if (!temp.nullo())
        return temp;
    // a questo punto so che nel sottoalbero sinistro non c'era un albero con 
// v come valore informativo
    return cerca(a.figlio(DES), v);
}
