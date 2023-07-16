#include <stdio.h>
#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending order
 *                       using the Insertion sort algorithm
 *
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *sorted;
	listint_t *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	
	current = (*list)->next;
	while (current != NULL)
	{
		sorted = current->prev;
		while (sorted != NULL && sorted->n > current->n)
		{
			tmp = current->next;
			if (tmp != NULL)
				tmp->prev = sorted;
			sorted->next = tmp;
			current->next = sorted;
			current->prev = sorted->prev;
			if (sorted->prev != NULL)
				sorted->prev->next = current;
			sorted->prev = current;
			if (current->prev == NULL)
				*list = current;
			print_list(*list);
			sorted = current->prev;
		}
		current = current->next;
	}
}
