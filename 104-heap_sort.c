#include <stdio.h>
#include "sort.h"

/**
 * sift_down - Performs the sift-down operation on a heap
 *
 * @array: The array representing the heap
 * @size: The size of the heap
 * @root: The root index of the subtree to sift-down
 * @end: The index where the sift-down should stop
 */
void sift_down(int *array, size_t size, size_t root, size_t end)
{
    size_t left_child, right_child, max_child;
    int temp;

    while ((left_child = (2 * root) + 1) <= end) {
        max_child = left_child;
        right_child = left_child + 1;

        if (right_child <= end && array[right_child] > array[left_child])
            max_child = right_child;

        if (array[root] < array[max_child]) {
            temp = array[root];
            array[root] = array[max_child];
            array[max_child] = temp;
            print_array(array, size);
            root = max_child;
        } else {
            break;
        }
    }
}

/**
 * heapify - Converts an array into a max heap
 *
 * @array: The array to be converted
 * @size: The size of the array
 */
void heapify(int *array, size_t size)
{
    ssize_t i;

    for (i = (size / 2) - 1; i >= 0; i--)
        sift_down(array, size, i, size - 1);
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
    size_t end;
    int temp;

    if (array == NULL || size < 2)
        return;

    heapify(array, size);

    end = size - 1;
    while (end > 0) {
        temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        print_array(array, size);
        sift_down(array, size, 0, end - 1);
        end--;
    }
}

