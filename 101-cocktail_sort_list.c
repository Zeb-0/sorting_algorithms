#include "sort.h"
#include <stdio.h>

/**
 * swap - Swaps two nodes
 * @a: The first node to be swaped
 * @b: The node swapped with the first node
 * @list: The doubly linked list
 */

void swap(listint_t *a, listint_t *b, listint_t **list)
{
	a->next = b->next;
	if (b->next != NULL)
		b->next->prev = a;
	if (a->prev == NULL)
	{
		b->next = a;
		a->prev = b;
		b->prev = NULL;
		*list = b;
	}
	else
	{
		a->prev->next = b;
		b->prev = a->prev;
		b->next = a;
		a->prev = b;
	}
}

/**
 * cocktail_sort_list - Sorts doubly linked list of integers
 * in ascending order using the Cocktail shaker algorithm
 * @list: The linked list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *x, *y;
	int swapped = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	x = (*list);
	while (swapped)
	{
		swapped = 0;
		while (x->next != NULL)
		{
			y = x->next;
			if (x->n > y->n)
			{
				swap(x, y, list);
				swapped = 1;
				print_list(*list);
			}
			else
				x = x->next;
		}
		if (swapped == 0)
			break;
		x = x->prev;
		while (x->prev)
		{
			y = x->prev;
			if (x->n < y->n)
			{
				swap(y, x, list);
				swapped = 1;
				print_list(*list);
			}
			else
				x = x->prev;
		}
		x = x->next;
	}
}
