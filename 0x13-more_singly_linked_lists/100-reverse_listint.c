#include "lists.h"

/**
 * reverse_listint - Reverses a listint_t list.
 * @head: Pointer to the pointer to the list's head.
 *
 * Description:
 * This function reverses the given list by changing the of its links.
 * It returns a pointer to the new head.
 *
 * Return: Pointer to the new head of the reversed list.
 */
listint_t *reverse_listint(listint_t **head)
{
listint_t *ahead, *behind;

if (head == NULL || *head == NULL)
return (NULL);

behind = NULL;

while ((*head)->next != NULL)
{
ahead = (*head)->next;
(*head)->next = behind;
behind = *head;
*head = ahead;
}

(*head)->next = behind;

return (*head);
}
