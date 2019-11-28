#include <cstdio>
#include <cstdlib>
#include <vector>
#include <time.h>

#include "sortlib.h"
#include "vecgen.h"

using namespace std;

void MainFunction(vector <long int> random_vector, long int N);

int main(int argc, char * argv[]){
    int N = atoi(argv[1]);
    vector <long int> random_vector;

    printf("Tamanho %d\n", N);
    printf("Random Vector: \n");
    random_vector = GenerateRandomVector(N, 0, N);
    MainFunction(random_vector, N);

    printf("Crescent Vector: \n");
    random_vector = GenerateCrescentVector(N);
    MainFunction(random_vector, N);

    printf("Decrescent Vector: \n");
    random_vector = GenerateDecrescentVector(N);
    MainFunction(random_vector, N);
    printf("\n");

    return 0;

}

void MainFunction(vector <long int> random_vector, long int N) {
    bool correct;
    clock_t t1, t2;
    vector <long int> ordered_vector;

    //Insertion Sort
    ordered_vector = random_vector;
    t1 = clock();
    InsertionSort(ordered_vector, N);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++){
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    }
    if (correct == false)
        printf("Insertion Sort Falhou!");
    printf("Insertion Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Selection Sort
    ordered_vector = random_vector;
    t1 = clock();
    SelectionSort(ordered_vector, N);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    if (correct == false)
        printf("Selection Sort Falhou!");
    printf("Selection Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Bubble Sort
    ordered_vector = random_vector;
    t1 = clock();
    BubbleSort(ordered_vector, N);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    if (correct == false)
        printf("Bubble Sort Falhou!");
    printf("Bubble Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Merge Sort
    ordered_vector = random_vector;
    t1 = clock();
    MergeSort(ordered_vector, 0, N - 1);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    if (correct == false)
        printf("Merge Sort Falhou!");
    printf("Merge Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Quick Sort
    ordered_vector = random_vector;
    t1 = clock();
    QuickSort(ordered_vector, 0, N - 1);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    if (correct == false)
        printf("Quick Sort Falhou!");
    printf("Quick Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Heap Sort
    ordered_vector.resize(1);
    ordered_vector.insert(ordered_vector.end(), random_vector.begin(), random_vector.end());
    t1 = clock();
    HeapSort(ordered_vector, N);
    t2 = clock();
    correct = true;
    for (int i = 2; i <= N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
           correct = false;
    if (correct == false)
        printf("Heap Sort Falhou!");
    printf("Heap Sort Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

    //Quick Sort Random
    ordered_vector = random_vector;
    t1 = clock();
    QuickSortRandom(ordered_vector, 0, N - 1);
    t2 = clock();
    correct = true;
    for (int i = 1; i < N; i++)
        if (ordered_vector[i] < ordered_vector[i - 1])
            correct = false;
    if (correct == false)
        printf("Quick Sort Random Falhou!");
    printf("Quick Sort Random Time: %.2f\n", (double)(t2-t1)/CLOCKS_PER_SEC * 1000);

}


