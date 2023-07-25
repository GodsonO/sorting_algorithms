#include "sort.h"

void swap(listint_t **head, listint_t *node_1, listint_t *node_2);
/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order using the Insertion sort algorithm
 * @list: list to be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_1, *node_2, *ptr;

	if (list == NULL || *list == NULL)
		return;

	if ((*list)->next == NULL)
		return;


	ptr = (*list)->next;
	node_2 = ptr;
	node_1 = ptr->prev;
	while (ptr != NULL)
	{
		while (node_1 != NULL && node_1->n > node_2->n)
		{
			swap(list, node_1, node_2);
			print_list(*list);
			node_1 = node_2->prev;
		}
		node_1 = ptr;
		ptr = ptr->next;
		node_2 = ptr;
	}

}
/**
 * swap - swaps two doubly linked nodes
 * @node_1: left node
 * @node_2: right node
 * @head: Head of the list
 * Return: void
 */
void swap(listint_t **head, listint_t *node_1, listint_t *node_2)
{
	listint_t *prev, *next;

	prev = node_1->prev;
	next = node_2->next;

	if (prev != NULL)
		prev->next = node_2;
	else
		*head = node_2;

	node_1->prev = node_2;
	node_1->next = next;
	node_2->prev = prev;
	node_2->next = node_1;
	if (next)
		next->prev = node_1;
}
