#include "sort.h"

/**
 * cocktail_sort_list - Sorts a doubly linked list of
 * integers using Cocktail Shaker Sort
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left, *right, *current;
	int swapped = 1;

	if (!list || !(*list) || !((*list)->next))
		return;

	while (swapped)
	{
		swapped = 0;
		current = *list;

		while (current->next)
		{
			if (current->n > current->next->n)
			{
				left = current->prev;
				right = current->next;

				if (left)
					left->next = right;
				else
					*list = right;
				if (right->next)
					right->next->prev = current;
				 current->prev = right;
				 current->next = right->next;
				 right->prev = left;
				 right->next = current;

				 swapped = 1;
				 print_list(*list);
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		current = current->prev;

		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				left = current->prev->prev;
				right = current;

				if (left)
					left->next = right;
				else
					*list = right;

				if (right->next)
					right->next->prev = current->prev;
				current->prev->prev = right;
				current->prev->next = right->next;
				right->prev = left;
				right->next = current->prev;

				swapped = 1;
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
