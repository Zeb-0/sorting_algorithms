#include "sort.h"

/**
* selection_sort - sorts an array of integers in ascending order
* @array : pointer array
* @size : size
*/

void selection_sort(int *array, size_t size)
{
	int val = 0, indx = 0, flag = 0;
	size_t i, j;

	if (array == NULL)
		return;
	for (i = 0; i < size - 1; i++)
	{
		val = array[i];
		for (j = i; j < size; j++)
		{
			if (val > array[j])
			{
				indx = j;
				val = array[j];
				flag = 1;
			}
		}
		if (flag == 1)
		{
			array[indx] = array[i];
			array[i] = val;
			print_array(array, size);
		}
		flag = 0;
	}
}
