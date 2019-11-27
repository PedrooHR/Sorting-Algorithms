#ifndef VECGEN_H_INCLUDED
#define VECGEN_H_INCLUDED

#include <vector>
#include <time.h>

using namespace std;

//Gera vetor crescente
vector <long int> GenerateCrescentVector(long int N){
    vector <long int> numbers;
    numbers.resize(N);

    for (long int i = 0; i < N; i++)
        numbers[i] = i;

    return numbers;
}

//Gera vetor decrescente
vector <long int> GenerateDecrescentVector(long int N){
    vector <long int> numbers;
    numbers.resize(N);

    for (long int i = 0; i < N; i++)
        numbers[i] = N - i - 1;

    return numbers;
}

//Gera vetor aleatório
vector <long int> GenerateRandomVector(long int N, long int Min, long int Max){
    srand(time(NULL));
    vector <long int> numbers;
    numbers.resize(N);

    for (long int i = 0; i < N; i++)
        numbers[i] = (long int) (Min + rand() % Max);

    return numbers;
}

#endif // VECGEN_H_INCLUDED
