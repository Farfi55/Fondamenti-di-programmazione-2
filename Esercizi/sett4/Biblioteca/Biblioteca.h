#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

class Biblioteca{


private:
	Libro* libri;
	unsigned sizeLibri;
	unsigned capLibri;

	Cliente* clienti;
	unsigned sizeClienti;
	unsigned capClienti;


	template<class T>
	void ridimensionaArray(T* &arr, unsigned& capacity);

	template<class T>
	void eliminaElemento(T* arr, unsigned& size, unsigned index); 


public:
	Biblioteca();

	void aggiungiLibro(Libro libro);
	void RimuoviLibro(int index);

	void aggiungiCliente(Cliente cliente);
	void RimuoviCliente(int index);

	Libro* cercaLibro(unsigned long ID);
	Libro* cercaLibro(string Nome);
};

template<class T>
void Biblioteca::ridimensionaArray(T* &arr, unsigned& capacity){

	T* tmp = new T[capacity * 2];
	
	for (int i = 0; i < capacity; i++)
		tmp[i] = arr[i];	

	delete [] arr;
	arr = tmp;
	capacity *=2; 
}

template<class T>
void Biblioteca::eliminaElemento(T* arr, unsigned& size, unsigned index){
	for(int i = index; i < size-1; i++);
		arr[i] = arr[i+1];

	size--;
}

//void Biblioteca::aggiungiLibro(Libro)


#endif
