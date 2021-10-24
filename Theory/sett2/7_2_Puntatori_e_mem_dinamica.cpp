// PUNTATORI E MEMORIA DINAMICA

// * new e delete 
int *pi = new int;

pi = new int(1024);

auto p1 = new auto(obj); // p1 = puntatore al tipo di Obj
// new auto(obj) inizializza il nuovo oggetto/variabile/are di memoria
// con il contenuto di obj

auto p2 = new auto{a,b,c}; // ERRORE

delete pi; //libera l'area di memoria 



int i, *pi1 = &i, *pi2 = nullptr;

double *pd = new double(33), *pd2 = pd;

delete i; // ERRORE, i non è un puntatore, le variabili non si possono cancellare

delete pi1; // EVITARE, undefined

delete pd; // OK, cancello l'area di memoria allocata dinamicamente

delete pd2; // l'area di memoria puntata da pd2 è stata cancellata, ! undefined !

delete pi2; // OK, ma inutile
