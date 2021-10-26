#include <iostream>
#include <string>
#include "Biblioteca.h"
#include "Libro.h"
#include "Cliente.h"

using namespace std;

int main() {

	Biblioteca biblioteca = Biblioteca();

	biblioteca.aggiungiLibro(Libro("Alice nel paese delle meraviglie",
		"Robert Wild;Daniel Winston"));

	
	

}

