#include "sort.h"

/**
 * insertion_sort_list -function that sorts doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Doubly linked list to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *node = (*list)->next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;


	while (node != NULL)
	{
		listint_t *current = node;
		listint_t *prev = current->prev;

		while (prev != NULL && prev->n > current->n)
		{
			prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = prev;

			current->next = prev;
			current->prev = prev->prev;
			prev->prev = current;

			if (current->prev != NULL)
				current->prev->next = current;
			else
				*list = current;

			prev = current->prev;
			print_list(*list);
		}

		node = node->next;
	}
}
