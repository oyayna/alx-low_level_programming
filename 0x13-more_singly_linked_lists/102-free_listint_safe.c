#include "lists.h"

/**
 * free_listp2 - Frees a list of pointers to structures and sets head to NULL.
 * @head: Pointer to the pointer to the list's head.
 *
 * Description:
 * This function deallocates memory for a list of pointers to structures
 * and sets the head pointer to NULL.
 */
void free_listp2(listp_t **head)
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
 * free_listint_safe - Safely frees a listint_t list (handles loops).
 * @h: Pointer to the pointer to the list's head.
 *
 * Description:
 * This function deallocates memory for a listint_t list, loops if present.
 *
 * Return: Number of nodes freed, or 0 if a loop is detected.
 */
size_t free_listint_safe(listint_t **h)
{
size_t nnodes = 0;
listp_t *hptr, *new, *add;
listint_t *curr;

hptr = NULL;
while (*h != NULL)
{
new = malloc(sizeof(listp_t));

if (new == NULL)
exit(98);

new->p = (void *)*h;
new->next = hptr;
hptr = new;

add = hptr;

while (add->next != NULL)
{
add = add->next;
if (*h == add->p)
{
*h = NULL;
free_listp2(&hptr);
return (nnodes);
}
}

curr = *h;
*h = (*h)->next;
free(curr);
nnodes++;
}

*h = NULL;
free_listp2(&hptr);
return (nnodes);
}
