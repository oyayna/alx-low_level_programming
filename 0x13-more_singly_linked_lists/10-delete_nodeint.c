#include "lists.h"

/**
 * delete_nodeint_at_index - Deletes a node at a  index in a listint_t list.
 * @head: Pointer to the pointer to the head of the list.
 * @index: The index of the node to delete.
 *
 * Description:
 * This function deletes the node at the  index in a listint_t list.
 * If the index is out of range or the list is empty, it returns -1.
 * Otherwise, it returns 1 after successfully deleting the node.
 *
 * Return: 1 on success, -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *prev;
	listint_t *next;

	prev = *head;

	if (index != 0)
	{
		for (i = 0; i < index - 1 && prev != NULL; i++)
		{
			prev = prev->next;
		}
	}

	if (prev == NULL || (prev->next == NULL && index != 0))
	{
		return (-1);
	}

	next = prev->next;

	if (index != 0)
	{
		prev->next = next->next;
		free(next);
	}
	else
	{
		free(prev);
		*head = next;
	}

	return (1);
}
