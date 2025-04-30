#include "input.h"

const int uniform_input[] = { 10000 };

void load_array(double** arr, long arr_size)
{
    *arr = malloc(arr_size * sizeof(double));

}
