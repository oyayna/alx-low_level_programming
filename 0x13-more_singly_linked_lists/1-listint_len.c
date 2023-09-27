#include "lists.h"

/**
 * listint_len - Counts the number of nodes in a listint_t list.
 * @h: Pointer to the head of the list.
 *
 * Description:
 * This function counts and returns the number of nodes in a listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t listint_len(const listint_t *h)
{
	size_t nnodes = 0;

	while (h != NULL)
	{
		h = h->next;
		nnodes++;
	}
	return (nnodes);
}
