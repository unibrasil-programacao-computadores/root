#include <stdio.h>
#include "sort.h"
#include "input.h"

int main()
{
    const char *file_pattern = "input/uniform-input-%ld-%d-float.txt";
    char file_path[50];
    long vec_size = uniform_input[0];
    int num_test = 1;
    double *arr;
    int count_numbers;

    arr = malloc(vec_size * sizeof(double));

    FILE *finput;
    sprintf(file_path, file_pattern, vec_size, num_test);
    finput = fopen(file_path, "r");
    if (finput == NULL)
    {
        printf("Unable to open the file: '%s'\n", file_path);
        return 1;
    }

    count_numbers = 0;
    while (count_numbers < vec_size && fscanf(finput, "%lf", &arr[count_numbers++]) == 1)
    {

    }

    fclose(finput);
    free(arr);

    run_quicksort(arr, vec_size);

    int i;
    for (i = 0; i < vec_size; ++i)
    {
        printf("%lf\n ", arr[i]);
    }

    return 0;
}
