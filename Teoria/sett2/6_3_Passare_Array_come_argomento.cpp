// C++ 11

#include <iostream>


void print(int[]);
void print(int*, int);

const int dim = 5;
int main(){
	int a[dim] = {1, 2, 3, 4, 5};
	
	for (auto elem:a)
		std::cout << elem << std::endl;

	std::cout << a;

}

void print(int ia[], int size){ }
void print(int *a, int size){ }

//per essere sicuri che l'array non venga modificato
void print(const int ia[], int size){ } 


void print(const int (&ia)[dim]){ } 

