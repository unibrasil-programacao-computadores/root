#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>

void quicksort(double* arr, long arr_size);

void selectionsort(double* arr, long arr_size);
void insertionsort(double* arr, long arr_size);

void shellsort(double* arr, long arr_size);
void mergesort(double* arr, long arr_size);
void heapsort(double* arr, long arr_size);

void countingsort(double* arr, long arr_size);
void radixsort(double* arr, long arr_size);
void bucketsort(double* arr, long arr_size);

#endif // SORT_H_INCLUDED
