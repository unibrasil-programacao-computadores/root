#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

#include <stdlib.h>

void quicksort(double* arr, double arr_size);

void selectionsort(double* arr, double arr_size);
void insertionsort(double* arr, double arr_size);

void shellsort(double* arr, double arr_size);
void mergesort(double* arr, double arr_size);
void heapsort(double* arr, double arr_size);

void countingsort(double* arr, double arr_size);
void radixsort(double* arr, double arr_size);
void bucketsort(double* arr, double arr_size);

#endif // SORT_H_INCLUDED
