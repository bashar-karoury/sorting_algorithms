#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
void swap_with_prev(listint_t *node);
/**
* insertion_sort_list - sorts a doubly linked list of integers in
* ascending order using the insertion sort
* @list: double pointer to list of integer
*/
void insertion_sort_list(listint_t **list)
{
	/*start with second node of list*/
	listint_t *trav_node = (*list)->next;
	listint_t *temp_node = NULL;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (trav_node != NULL)
	{
		temp_node = trav_node->next;
		/*compare with previouse node till the head*/
		while (trav_node->prev != NULL)
		{
			if (trav_node->n < (trav_node->prev)->n)
			{
				/*swap two nodes*/
				swap_with_prev(trav_node);
				if (trav_node->prev == NULL)
				{
					/* new head node*/
					*list = trav_node;
				}
				/*trav_node = trav_node->prev;*/
				print_list(*list);
			}
			else
			{
				break;
			}
		}
		trav_node = temp_node;
	}
}

/**
* swap_with_prev - swaps the node with its previous
* @node: pointer of node to be swapped
*/
void swap_with_prev(listint_t *node)
{
	listint_t *next = node->next;
	listint_t *prev = node->prev;
	listint_t *p_prev = NULL;

	p_prev = prev->prev;
	node->prev = p_prev;
	if (p_prev)
		p_prev->next = node;
	node->next = prev;
	prev->prev = node;
	prev->next = next;
	if (next)
		next->prev = prev;
}
