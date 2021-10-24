#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

class Biblioteca{


private:
	Libro* libri;
	unsigned nLibri;

	Cliente* clienti;
	unsigned nClienti;


	template<class T>
	void ridimensionaArray(T* &arr, unsigned& size);

	template<class T>
	void eliminaElemento(T* arr, unsigned size, unsigned index); 


public:
	Biblioteca();

	void aggiungiLibro()
	void RimuoviLibro()

	void aggiungiCliente()
	void RimuoviCliente()

	Libro* cercaLibro(unsigned long ID);
	Libro* cercaLibro(string Nome);
}



#endif
