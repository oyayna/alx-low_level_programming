#include "lists.h"

/**
 * free_listp - Frees a list of listp_t nodes and sets the head to NULL.
 * @head: Pointer to the pointer to the head of the list.
 *
 * Description:
 * This function a linked list of listp_t and sets the head pointer to NULL.
 * If the list is empty or the head pointer is NULL, it does nothing.
 */
void free_listp(listp_t **head)
{
	listp_t *temp;
	listp_t *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp);
		}
		*head = NULL;
	}
}

/**
 * print_listint_safe - Prints a listint_t list safely, handling loops.
 * @head: Pointer to the head of the list.
 *
 * Description:
 * This function prints the of a listint_t list, handling loops if present.
 * It also counts and returns the number of nodes in the list.
 * If memory allocation fails, it exits with status code 98.
 *
 * Return: Number of nodes in the list, or 0 if a loop is detected.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nnodes = 0;
	listp_t *hptr, *new, *add;

	hptr = NULL;
	while (head != NULL)
	{
		new = malloc(sizeof(listp_t));

		if (new == NULL)
			exit(98);

		new->p = (void *)head;
		new->next = hptr;
		hptr = new;

		add = hptr;

		while (add->next != NULL)
		{
			add = add->next;
			if (head == add->p)
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free_listp(&hptr);
				return (nnodes);
			}
		}

		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
		nnodes++;
	}

	free_listp(&hptr);
	return (nnodes);
}

