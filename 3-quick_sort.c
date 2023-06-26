#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two integers.
 * @a: Pointer to the first integer.
 * @b: Pointer to the second integer.
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	
}

/**
 * partition - Lomuto partition scheme for quicksort.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 *
 * Return: The index of the pivot element.
 */
int partition(int *array, int low, int high)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quicksort.
 * @array: The array to be sorted.
 * @low: Starting index of the partition.
 * @high: Ending index of the partition.
 */
void quick_sort_recursive(int *array, int low, int high)
{
	/*int i;*/

	if (low < high)
	{
		int pivot = partition(array, low, high);

		/*printf("\n");
		for (i = low; i <= high; i++)
		{
			printf("%d", array[i]);
			if (i != high)
				printf(", ");
		}*/

		quick_sort_recursive(array, low, pivot - 1);
		quick_sort_recursive(array, pivot + 1, high);
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

	quick_sort_recursive(array, 0, size - 1);
}
