#include "input.h"

const int size_inputs[] =
{
    10000, 50000,
    100000, 200000, 300000, 400000, 500000, 600000, 700000, 800000, 900000,
    1000000, 2000000, 3000000, 4000000,
};

void load_array(double** arr, long arr_size, const char *file_path)
{
    FILE *finput;
    int count_numbers;

    *arr = malloc(arr_size * sizeof(double));

    finput = fopen(file_path, "r");

    if (finput == NULL)
    {
        fprintf(stderr, "Unable to open file: '%s'\n", file_path);
        exit(EXIT_FAILURE);
    }

    count_numbers = 0;
    while (count_numbers < arr_size && fscanf(finput, "%lf", &(*arr)[count_numbers++]) == 1);

    fclose(finput);
}

void print_array(const double *arr, long vec_size)
{
    int i;

    for (i = 1; i <= vec_size; ++i)
    {
        printf("%lf  ", arr[i - 1]);
        if (!(i % NUMBERS_PER_LINE)) printf("\n");
    }
}

void sort_base_array(void (*algorithm) (double* arr, long arr_size), const char* name)
{
    double *arr;
    clock_t start, end;
    double cpu_time;

    load_array(&arr, LENGTH_BASE_ARRAY, FILE_PATH_BASE_ARRAY);

    start = clock();
    algorithm(arr, LENGTH_BASE_ARRAY);
    end = clock();

    cpu_time = (double)(end - start) / CLOCKS_PER_SEC;
    print_array(arr, LENGTH_BASE_ARRAY);
    printf("%s - Vector Size: %d - CPU time : %.6f seconds\n", name, LENGTH_BASE_ARRAY, cpu_time);

    free(arr);
}

void sort_uniform_arrays(void (*algorithm) (double* arr, long arr_size), const char* name)
{
    int num_input_files, test, input, vec_size;
    char file_path[50];
    double *arr;
    clock_t start, end;
    double cpu_time[NUM_TESTS_PER_FILE], sum_cpu_time;

    num_input_files = sizeof(size_inputs) / sizeof(int);

    printf("\nSorting files with format: %s\n", UNIFORM_FILE_PATTERN);

    for (input = 0; input < num_input_files; input++)
    {
        for (test = 1; test <= NUM_TESTS_PER_FILE; test++)
        {
            vec_size = size_inputs[input];
            sprintf(file_path, UNIFORM_FILE_PATTERN, vec_size, test);

            if (DEBUG) printf("Sorting %s\n", file_path);

            load_array(&arr, vec_size, file_path);

            start = clock();
            algorithm(arr, vec_size);
            end = clock();
            cpu_time[test - 1] = (double)(end - start) / CLOCKS_PER_SEC;

            free(arr);

            if (DEBUG) printf("%s - Vector Size: %d - CPU time : %.6f seconds\n", name, vec_size, cpu_time[test - 1]);
        }

        // Calculating the Average CPU time
        sum_cpu_time = 0;
        for (test = 0; test < NUM_TESTS_PER_FILE; test++)
        {
            sum_cpu_time += cpu_time[test];
        }

        printf("%s [%02d/%d] - Vector Size: %d - CPU time : %.6f seconds\n",
               name, input + 1, num_input_files, vec_size, sum_cpu_time / NUM_TESTS_PER_FILE);
    }
}

void sort_arrays(void (*algorithm) (double* arr, long arr_size), const char* name, const char* file_pattern)
{
    int num_input_files, input, vec_size;
    char file_path[50];
    double *arr;
    clock_t start, end;
    double cpu_time;

    num_input_files = sizeof(size_inputs) / sizeof(int);

    printf("\nSorting files with format: %s\n", file_pattern);

    for (input = 0; input < num_input_files; input++)
    {
        vec_size = size_inputs[input];
        sprintf(file_path, file_pattern, vec_size);

        if (DEBUG) printf("Sorting %s\n", file_path);

        load_array(&arr, vec_size, file_path);

        start = clock();
        algorithm(arr, vec_size);
        end = clock();
        cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

        free(arr);

        printf("%s [%02d/%d] - Vector Size: %d - CPU time : %.6f seconds\n",
               name, input + 1, num_input_files, vec_size, cpu_time);
   }
}

void sort_ordered_arrays(void (*algorithm) (double* arr, long arr_size), const char* name)
{
    sort_arrays(algorithm, name, ORDERED_FILE_PATTERN);
}

void sort_reverse_ordered_arrays(void (*algorithm) (double* arr, long arr_size), const char* name)
{
    sort_arrays(algorithm, name, REVERSE_ORDERED_FILE_PATTERN);
}
