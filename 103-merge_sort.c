#include "sort.h"
#include <stdlib.h>

/**
 * sub_arr - Merges the sub-arrays.
 * @sub_array: The smaller array to be sorted.
 * @buff: A copy of the array.
 * @left: The lower index at the LHS.
 * @right: The higher index at the RHS.
 * @mid: The index in the middle
 */

void sub_arr(int *sub_array, int *buff, size_t left, size_t mid, size_t right)
{
	size_t a = left, b = mid, c = 0;

	printf("Merging...\n[left]: ");
	print_array(sub_array + left, mid - left);

	printf("[right]: ");
	print_array(sub_array + mid, right - mid);

	while (a < mid && b < right)
	{
		if (sub_array[a] < sub_array[b])
		{
			buff[c] = sub_array[a];
			a++;
		}
		else
		{
			buff[c] = sub_array[b];
			b++;
		}
		c++;
	}
	while (b < right)
	{
		buff[c] = sub_array[b];
		b++;
		c++;
	}
	while (a < mid)
	{
		buff[c] = sub_array[a];
		a++;
		c++;
	}
	for (a = left, c = 0; a < right; a++, c++)
		sub_array[a] = buff[c];

	printf("[Done]: ");
	print_array(sub_array + left, right - left);
}

/**
 * merge_top_down - Implement the merge sort algorithm through recursion.
 * @sub_array: The smaller array to be sorted.
 * @buff: A copy of the array.
 * @left: The lower index at the LHS.
 * @right: The higher index at the RHS.
 */

void merge_top_down(int *sub_array, int *buff, size_t left, size_t right)
{
	size_t mid;

	if (right - left > 1)
	{
		mid = (left + right) / 2;
		merge_top_down(sub_array, buff, left, mid);
		merge_top_down(sub_array, buff, mid, right);
		sub_arr(sub_array, buff, left, mid, right);
	}
}

/**
 * merge_sort - Sorts an array of integers in ascending
 * order using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array
 */

void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	merge_top_down(array, buff, 0, size);
	free(buff);
}
