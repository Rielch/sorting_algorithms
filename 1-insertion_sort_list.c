#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list using the inserion sort
 *
 * @list: doubly linked list
 * Return: Void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *actual, *change;

	if (list == NULL || *list == NULL)
		return;

	temp = *list;
	actual = temp->next;
	while (actual != NULL)
	{
		change = actual->prev;
		temp = actual->next;
		while (change->n > actual->n)
		{
			if (actual->next != NULL)
				actual->next->prev = change;
			if (change->prev != NULL)
				change->prev->next = actual;
			change->next = actual->next;
			actual->prev = change->prev;
			actual->next = change;
			change->prev = actual;
			if (actual->prev != NULL)
				change = actual->prev;
			else
			{
				*list = actual;
				print_list(*list);
				break;
			}
			print_list(*list);
		}
		actual = temp;
	}
}
