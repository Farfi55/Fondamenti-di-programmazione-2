/**
 * * MERGE SORT
 * O(n log(n) ) C.P.
 * O(n log(n) ) C.M.
 *
 */

void mergeSort(int v[], int in, int fin) {
    if ((fin - in) < 20)
        insertionSort(V, in, fin);
    else {
        int medio = (in + fin) / 2;

        // scomposizione dei sottoproblemi
        mergeSort(v, in, medio);
        mergeSort(v, medio + 1, fin);

        // ricomposizione dei sottoproblemi
        merge(v, in, fin, medio);
    }
}

void merge(int v[], int in, int fin, int medio) {
    int a[fin - in];
    int i1 = in, i2 = medio + 1;
    int i3 = 0;

    while (i1 <= medio && i2 <= fin) {
        if (v[i1]) < V[i2])
			a[i3++] = v[i1++]		
		else
			a[i3++] = v[i2++]
    }
    // se rimangono "residui" a sinistra
    while (i1 <= medio)
        a[i3++] = v[i1++]

            // se rimangono "residui" a destra
            while (i2 <= fin) a[i3++] = v[i2++]

            for (i3 = 0, i1 = in; i1 <= fin; i3++, i1 +) {
            v[i1] = a[i3];
        }
}

/**
 * * QUICK SORT
 * https://www.wikiwand.com/it/Quicksort
 *
 *  - partizionamento
 *
 * ___________|x|_________
 *    < x           > x
 *
 *
 *  15  7  2 21 34  8 19  5 23  4  9 22 13
 *
 *
 * C.P. O(n^2)
 * C. Medio O(n log(n))
 *
 *
 */

void quickSort(int v[], int in, int fin) {
    if (fin - in <)
        insertionSort(v, in, fin);
    else {
        int posOrd = partiziona(V, in, fin);
        quickSort(v, in, posOrd - 1);
        quickSort(v, posOrd + 1, fin);

        // nessuna ricomposizione, visto che x sarà già nella giusta posizione
    }
}

int partiziona(int v[], int in, int fin) {
    // scambio un elemento random con il primo
    // così da ridurre la probabilità del caso peggiore
    int r = abs(rand());
    int iCasuale = (r % (fin - in + 1)) + in;
    scambia(v[in], v[iCasuale]);

    int i = in, j = fin + 1;
    while (i < j) {
        do j--;
        while (v[in] < v[j]);

        do i++;
        while (v[in] >= v[j]);

        if (i < j) scambia(v[i], v[j]);
    }
    scambia(v[in], v[j]);
    return j;
}

void scambia(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
