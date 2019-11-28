#ifndef SORTLIB_H_INCLUDED
#define SORTLIB_H_INCLUDED

#include <vector>
#include <time.h>

using namespace std;

void InsertionSort(vector <long int> & numbers, long int N){
// Insertion Sort
    long int aux, i, j;

    for (i = 1; i < N; i++){
        aux = numbers[i];
        j = i - 1;

        while (j >= 0 && numbers[j] > aux){
            numbers[j + 1] = numbers [j];
            j = j - 1;
        }

        numbers[j + 1] = aux;
    }
}

// Selection Sort
void SelectionSort(vector <long int> & numbers, long int N){
    long int cmin, i, j;

    for (i = 0; i < N - 1; i++){
        cmin = i;

        for (j = i + 1; j < N; j++){
            if (numbers[j] < numbers[cmin]){
                cmin = j;
            }
        }

        if (i != cmin) {
            long int aux = numbers[cmin];
            numbers[cmin] = numbers[i];
            numbers[i] = aux;
        }
    }
}

// Bubble Sort
void BubbleSort(vector <long int> & numbers, long int N){
    long int aux, i, j;

    for (i = N - 1; i >= 1; i--){
        for (j = 0; j < i; j++){
            if (numbers[j] > numbers[j + 1]){
                aux = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = aux;
            }
        }
    }
}

/* Start of Merge Sort Algorithm */
void MergeIntercala(vector <long int> & numbers, long int p, long int q, long int r){
    vector <long int> w;
    w.resize(r - p + 1);
    int i, j, t, k = 0;
    i = p;
    j = q + 1;
    while (i <= q && j <= r ){
        if (numbers[i] <= numbers[j]){
            w[k++] = numbers[i];
            i++;
        } else {
            w[k++] = numbers[j];
            j++;
        }
    }
    while (i <= q){
        w[k++] = numbers[i];
        i++;
    }
    while (j <= r){
        w[k++] = numbers[j];
        j++;
    }
    for (t = 0; t < k; t++){
        numbers[p + t] = w[t];
    }
}

void MergeSort( vector <long int> & numbers, long int p, long int r){
    if ((r - p) >= 1){
        long int q = (p + r) / 2;
        MergeSort(numbers, p, q);
        MergeSort(numbers, q + 1, r);
        MergeIntercala(numbers, p, q, r);
    }
}

/* Start of Quick Sort Algorithm */
long int QuickParticiona(vector <long int> & numbers, long int p, long int r){
    int x, j, i, aux;
    i = p - 1;
    j = r + 1;
    x = numbers[p];

    while (i < j){
        do {
            i = i + 1;
        } while (numbers[i] < x);
        do {
            j = j - 1;
        } while (numbers[j] > x);

        if (i < j){
            aux = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = aux;
        }
    }

    return j;
}

void QuickSort(vector <long int> & numbers, long int p, long int r){
    if (r > p){
        long int q = QuickParticiona(numbers, p, r);
        QuickSort(numbers, p, q);
        QuickSort(numbers, (q + 1), r);
    }
}

/* Start of Random Quick Sort Algorithm */
long int QuickRParticiona(vector <long int> & numbers, long int p, long int r){
    int x, j, i, aux;
    i = p - 1;
    j = r + 1;
    srand(time(NULL));
    x = numbers[p + rand() % (r-p)];
    //x = numbers[(p+r)/2];
    while (i < j){
        do {
            i = i + 1;
        } while (numbers[i] < x);
        do {
            j = j - 1;
        } while (numbers[j] > x);

        if (i < j){
            aux = numbers[i];
            numbers[i] = numbers[j];
            numbers[j] = aux;
        }
    }

    return j;
}

void QuickSortRandom(vector <long int> & numbers, long int p, long int r){
    if (r > p){
        long int q = QuickRParticiona(numbers, p, r);
        QuickSortRandom(numbers, p, q);
        QuickSortRandom(numbers, (q + 1), r);
    }
}

/* Start of Heap Sort Algorithm */
void HeapRestaura(vector <long int> & numbers, long int i, long int N){
    long int j = i, k;
    bool regra2 = false;
    while ((j <= (N / 2)) && (regra2 == false)){
        if (2 * j < N){
            if (numbers[2 * j] < numbers[2 * j + 1]) {
                k = 2 * j + 1;
            } else {
                k = 2 * j;
            }
        } else {
            k = 2 * j;
        }

        if (numbers[j] < numbers[k]){
            long int aux = numbers[j];
            numbers[j] = numbers[k];
            numbers[k] = aux;
            j = k;
        } else {
            regra2 = true;
        }
    }
}

void HeapConstroi(vector <long int> & numbers, long int N){
    for (long int i = N / 2; i >= 1; i--){
        HeapRestaura(numbers, i, N);
    }
}

void HeapOrdena(vector <long int> & numbers, long int N){
    long int u = N;
    while (u > 1){
        long int aux = numbers[1];
        numbers[1] = numbers[u];
        numbers[u] = aux;

        u = u - 1;
        HeapRestaura(numbers, 1, u);
    }
}

void HeapSort(vector <long int> & numbers, long int N){
    HeapConstroi(numbers, N);
    HeapOrdena(numbers, N);
}

#endif // SORTLIB_H_INCLUDED
