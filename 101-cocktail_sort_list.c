#include "sort.h"

/**
 * swap - swaps two nodes
 * @head: head of the list
 * @node1: first node to sort
 * @node2: second node to sort
 */

void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *prev, *next;

	prev = node1->prev;
	next = node2->next;

	if (prev != NULL)
		prev->next = node2;
	else
		*head = node2;

	node1->prev = node2;
	node1->next = next;
	node2->prev = prev;
	node2->next = node1;

	if (next != NULL)
		next->prev = node1;
}

/**
 * cocktail_sort_list - sorts a list using the cocktail sort algorithm
 * @list: list to sort
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *tail;
	int swapped;

	if (!list || !(*list) || !(*list)->next)
		return;

	do {
		swapped = 0;
		for (head = *list; head->next != tail; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap(list, head, head->next);
				print_list(*list);
				swapped = 1;
			}
		}
		tail = head;

		if (!swapped)
			break;

		swapped = 0;
		for (; head->prev != NULL; head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap(list, head->prev, head);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}
