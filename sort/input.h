#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH_BASE_ARRAY 1000
#define FILE_PATH_BASE_ARRAY "input/uniform-input-1000-float.txt"
#define FILE_PATH_PATTERN "input/uniform-input-%d-%d-float.txt"
#define NUM_TESTS_PER_FILE 3
#define DEBUG 0

extern const int uniform_input[];

void load_array(double** arr, long arr_size, const char *file_path);
void print_array(const double *arr, long vec_size);
void sort_base_array(void (*algorithm) (double* arr, double arr_size), const char* name);
void sort_uniform_arrays(void (*algorithm) (double* arr, double arr_size), const char* name);


#endif // INPUT_H_INCLUDED
