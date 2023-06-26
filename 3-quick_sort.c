#include "sort.h"
#include <stdio.h>

/**
 * divide_and_sort - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @size: the size of the array for printing it.
 * @start: Starting index of the partition.
 * @end: Ending index of the partition.
 *
 * Return: The index of the pivot element.
 */
int divide_and_sort(int *array, size_t size, int start, int end)
{
	int pivot, idx, j, temp;

	pivot = array[end];
	idx = start;

	for (j = start; j < end; j++)
	{
		if (array[j] < pivot)
		{
			if (array[idx] != array[j])
			{
				temp = array[idx];
				array[idx] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
			idx++;
		}
	}
	if (array[idx] != array[end])
	{
		temp = array[idx];
		array[idx] = array[end];
		array[end] = temp;
		print_array(array, size);
	}

	return (idx);
}

/**
 * quick_sort_recurse - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @size: the size of the array for printing it.
 * @start: Starting index of the partition.
 * @end: Ending index of the partition.
 */
void quick_sort_recurse(int *array, size_t size, int start, int end)
{
	int p;

	if (start < end && end > 0) /* base case if false */
	{
		p = divide_and_sort(array, size, start, end);
		quick_sort_recurse(array, size, start, p - 1);
		quick_sort_recurse(array, size, p + 1, end);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recurse(array, size, 0, size - 1);
}
