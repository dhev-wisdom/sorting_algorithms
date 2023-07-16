#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into a sorted array
 *
 * @array: The array containing the subarrays to be merged
 * @left: The left subarray
 * @left_size: The size of the left subarray
 * @right: The right subarray
 * @right_size: The size of the right subarray
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
    size_t i, j, k;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(left, left_size);
    printf("[right]: ");
    print_array(right, right_size);

    i = 0;
    j = 0;
    k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }

    printf("[Done]: ");
    print_array(array, left_size + right_size);
}

/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
    size_t mid;
    int *left, *right;

    if (array == NULL || size < 2)
        return;

    mid = size / 2;
    left = array;
    right = array + mid;

    merge_sort(left, mid);
    merge_sort(right, size - mid);

    printf("\nMerging...\n");
    printf("[left]: ");
    print_array(left, mid);
    printf("[right]: ");
    print_array(right, size - mid);

    merge(array, left, mid, right, size - mid);

    printf("[Done]: ");
    print_array(array, size);
}

