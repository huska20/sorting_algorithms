#include "sort.h"

/**
 * bubble_sort - sorts an array in ascending order using the
 * bubble sort algorithm.
 * @array: the array.
 * @size: the size of the array.
 *
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swap_flag;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		if (i == size - 1)
			break;

		swap_flag = 0;
		for (j = 0; j < size - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				swap_flag = 1;
			}
		}

		if (swap_flag == 0)
			break;
	}
}

