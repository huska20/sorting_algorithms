#include "sort.h"

/**
 * selection_sort - sorts an array in ascending order using the
 * selection sort algorithm.
 * @array: the array
 * @size: the size of the array
 *
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;
	int temp;

	if (size < 2)
	{
		return;
	}

	/**
	 * by the time last element is reached the left
	 * side of the element is sorted
	 */
	for (i = 0; i < size - 2; i++)
	{
		min_idx = i;
		for (j = i; j <= size - 1; j++)
		{
			if (array[j] < array[min_idx])
			{
				min_idx = j;
			}
		}
		if (i != min_idx)
		{
			temp = array[i];
			array[i] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
