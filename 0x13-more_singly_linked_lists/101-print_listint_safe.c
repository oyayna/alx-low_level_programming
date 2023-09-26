#include "lists.h"
#include <stdio.h>

size_t looped_listint_len(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * looped_listint_len - Finds the number of nodes in a looped list.
 * @head: Pointer to the head of the list.
 *
 * Description:
 * This function determines the number of nodes in a looped list.
 *
 * Return: Number of nodes in the loop, or 0 if no loop is found.
 */
size_t looped_listint_len(const listint_t *head)
{
const listint_t *tortoise, *hare;
size_t nodes = 1;

if (head == NULL || head->next == NULL)
return (0);

tortoise = head->next;
hare = (head->next)->next;

while (hare)
{
if (tortoise == hare)
{
tortoise = head;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
hare = hare->next;
}

tortoise = tortoise->next;
while (tortoise != hare)
{
nodes++;
tortoise = tortoise->next;
}

return (nodes);
}

tortoise = tortoise->next;
hare = (hare->next)->next;
}

return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely (handles loops).
 * @head: Pointer to the head of the list.
 *
 * Description:
 * This function prints the elements of a list, handling loops if present.
 *
 * Return: Number of nodes in the list, or 0 if a loop is detected.
 */
size_t print_listint_safe(const listint_t *head)
{
size_t nodes, index = 0;

nodes = looped_listint_len(head);

if (nodes == 0)
{
for (; head != NULL; nodes++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}
}

else
{
for (index = 0; index < nodes; index++)
{
printf("[%p] %d\n", (void *)head, head->n);
head = head->next;
}

printf("-> [%p] %d\n", (void *)head, head->n);
}

return (nodes);
}
