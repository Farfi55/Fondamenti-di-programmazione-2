int ia[] = {0,1,2,3,4,5,6,7,8,9};
auto ia2 = ia; //int*, equivalente a ia2 = &a[0]
int *p = ia; // equivalente

#if 0
ia2 = 42; // ERRORE, non posso assegnare un valore intero ad un puntatore
ia2++; // aumenta il puntatore e punta al prossimo int
#endif

cout << ia2 << endl; // indirizzo
cout << *ia2 << endl; // stampa ia2[0]
cout << ia2[1] << endl; // stampa ia2[1], cioè il secondo elemento
ia2++;
cout << *ia2 << endl; // stampa ia2[1]
cout << ia2[1] << endl; // stampa ia2[2], cioè il terzo elemento


// funzioni begin, end

// begin : punta al primo elemento di una lista
// end : punta alla cella successiva dell'ultimo elemento

auto n = end(ia) - begin(ia); // n = 10

int* beg = begin(ia);
int* last = end(ia);

while (beg != last){
	count << *beg << " ";
	++beg;
}

// equivalente a 

int b = 0, e = 10;
while (b != e)
{
	cout << ia[b] << " ";
	b++
}
// -----------


int ia3[] = {0,1,2,3,4,5,6,7,8,9};
int medio = (end(ia3) - begin(ia3)-1)/2;

int *p3 = &ia3[medio];

/*
	0		1		2		3		4		5		6		7		8		9
	ia[0]	ia[1]	ia[2]	ia[3]	ia[4]	ia[5]	ia[6]	ia[7]	ia[8]	ia[9]
	p[-4]	p[-3]	p[-2]	p[-1]	p[0]	p[1]	p[2]	p[3]	p[4]	p[5]
*/


