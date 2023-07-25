#include "sort.h"

/**
* insertion_sort_list - sorts a doubly linked list in ascending order
* @list : dobly linked list
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *head;

	if (list == NULL)
		return;
	head = *list;
	while (head->next != NULL)
	{
		while (head->next != NULL)
		{
			if (head->n > head->next->n)
			{
				temp = head;
				if (head->prev != NULL)
					head->prev->next = temp->next;
				head->next->prev = temp->prev;
				head->prev = temp->next;
				head->next = temp->next->next;
				head->prev->next = temp;
				if (head->next != NULL)
					head->next->prev = temp;
				if (head->prev->prev == NULL)
					*list = head->prev;
				print_list(*list);
				head = *list;
				break;
			}
			head = head->next;
		}
	}
}
