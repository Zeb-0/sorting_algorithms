#include "sort.h"

/**
* bubble_sort - sorts an array of integers in ascending order
* @array : pointer array
* @size : size
*/

void bubble_sort(int *array, size_t size)
{
	int temp = 0;
	size_t i, j;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
}
