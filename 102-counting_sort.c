#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 *                 using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *count = NULL, *output = NULL;
    size_t i, max = 0;

    if (array == NULL || size < 2)
        return;

    for (i = 0; i < size; i++) {
        if (array[i] > (int)max)
            max = array[i];
    }

    count = malloc(sizeof(int) * (max + 1));
    if (count == NULL)
        return;

    output = malloc(sizeof(int) * size);
    if (output == NULL) {
        free(count);
        return;
    }

    for (i = 0; i <= max; i++)
        count[i] = 0;

    for (i = 0; i < size; i++)
        count[array[i]]++;

    printf("%d", count[0]);
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
        printf(", %d", count[i]);
    }
    printf("\n");

    for (i = 0; i < size; i++) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output[i];

    free(output);
    free(count);
}

