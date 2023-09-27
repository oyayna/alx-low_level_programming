#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a in a listint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @idx: The index at which the new node should be inserted.
 * @n: The integer value to store in the new node.
 *
 * Description:
 * This function inserts a new node with the value at the in a listint_t list.
 * If the index is out of range or memory allocation fails, it returns NULL.
 * Otherwise, it returns a pointer to the newly inserted node.
 *
 * Return: Pointer to the newly inserted node on success, or NULL on failure.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i;
	listint_t *new;
	listint_t *h;

	h = *head;

	if (idx != 0)
	{
		for (i = 0; i < idx - 1 && h != NULL; i++)
		{
			h = h->next;
		}
	}

	if (h == NULL && idx != 0)
		return (NULL);

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;

	if (idx == 0)
	{
		new->next = *head;
		*head = new;
	}
	else
	{
		new->next = h->next;
		h->next = new;
	}

	return (new);
}
