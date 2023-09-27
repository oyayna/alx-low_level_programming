#include "lists.h"

/**
 * print_listint - Prints the elements of a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Description:
 * This function prints the integer elements of a list, one per line.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint(const listint_t *h)
{
	size_t nnodes = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nnodes++;
	}
	return (nnodes);
}
