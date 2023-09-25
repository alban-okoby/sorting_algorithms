#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of
 * integers using Insertion Sort
 * @list: Pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next;

	if (!list || !*list || !(*list)->next)
		return;

	while (current)
	{
		listint_t *temp = current;
		listint_t *prev = current->prev;

		while (prev && prev->n > temp->n)
		{
			prev->next = temp->next;
			if (temp->next)
				temp->next->prev = prev;
			temp->prev = prev->prev;
			temp->next = prev;

			if (prev->prev)
				prev->prev->next = temp;
			else
				*list = temp;
			prev->prev = temp;
			print_list(*list);
			prev = temp->prev;
		}
		current = current->next;
	}
}
