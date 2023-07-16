#include <stdio.h>
#include "sort.h"

/**
 * swap - Swaps two integers
 *
 * @a: First integer
 * @b: Second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * hoare_partition - Partitions the array using the Hoare partition scheme
 *
 * @array: The array to be partitioned
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 *
 * Return: The partition index
 */
size_t hoare_partition(int *array, ssize_t low, ssize_t high)
{
    int pivot = array[high];
    ssize_t i = low - 1;
    ssize_t j = high + 1;

    while (1) {
        do {
            i++;
        } while (array[i] < pivot);

        do {
            j--;
        } while (array[j] > pivot);

        if (i >= j)
            return (j);

        swap(&array[i], &array[j]);
        print_array(array, high - low + 1);
    }
}

/**
 * quicksort - Recursive function to sort the array using Quick sort
 *
 * @array: The array to be sorted
 * @low: The starting index of the partition
 * @high: The ending index of the partition
 */
void quicksort(int *array, ssize_t low, ssize_t high)
{
    size_t partition;

    if (low < high) {
        partition = hoare_partition(array, low, high);
        quicksort(array, low, partition);
        quicksort(array, partition + 1, high);
    }
}

/**
 * quick_sort_hoare - Sorts an array of integers in ascending order
 *                    using the Quick sort algorithm with the Hoare partition scheme
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort_hoare(int *array, size_t size)
{
    if (array == NULL || size < 2)
        return;

    quicksort(array, 0, size - 1);
}

