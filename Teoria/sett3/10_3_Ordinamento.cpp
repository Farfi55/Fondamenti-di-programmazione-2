// ORDINAMENTO
// in loco
/**
 * Bubble Sort
 * 	C.P. O(n^2)
 * 	C.M. O(n)
 *
 * Selection Sort
 *	C.P. O(n^2) 	in termini di costanti è meglio del Bouble sort
 * 	C.M. O(n^2)
 *
 *
 * Insertion Sort
 *  C.P. O(n^2)
 * 	C.M. O(n)
 *
 * Integer Sort
 *  C.P. O(n*k)
 */

// * BOUBLE SORT

void bublesort(int a[], int n) {
    bool scambi;

    int x = n, lastSwap;

    do {
        scambi = false;
        for (int i = 0; i < x - 1; i++) {
            // O(1)
            if (a[i] > a[i + 1]) {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
                scambi = true;
                lastSwap = i + 1;
            }
            x = lastSwap;
        }
    } while (scambi);

    return a[];
}

/**
 * studio complessità
 * CASO PEGGIORE :
 * array ordinato al contrario
 *
 * iter 1: n-1
 * iter 2: n-2
 * iter 3: n-3
 * iter 4: n-4
 * ...
 * iter n-1: 1
 * ------------
 * 	~ n(n+1)/2 ----> O(n^2)
 *
 *
 * CASO MIGLIORE :
 * array già ordinato
 * controllo ogni posizione
 * O(n)
 *
 */

// * SELECTION SORT

void SelectionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int min = i;

        for (int j = 0; j < n - i; j++)
            if (a[j] < min) min = j;

        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}

/**
 * STUDIO COMPLESSITA':
 * CASO PEGIGORE :
 * array ordinato al contrario
 *
 * iter 1: n cicli
 * iter 2: n-1
 * iter 3: n-2
 * ...
 * iter n: 1
 * --------------
 *   ~ n(n+1)/2 ----> O(n^2)
 *
 * CASO MIGLIORE :
 *	O(n^2)
 *
 */

// * INSERTION SORT

void InsertionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int temp = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

/**
 * * STUDIO COMPLESSITA':
 * CASO PEGIGORE :
 * array ordinato al contrario
 *
 * iter 1: n-1 cicli
 * iter 2: n-2
 * iter 3: n-3
 * ...
 * iter n-1: 1
 * --------------
 *  ~ n(n+1)/2 ----> O(n^2)
 *
 * CASO MIGLIORE :
 * array già ordinato
 *
 * il while finisce sempre subito quindi
 *  O(n)
 *
 */
