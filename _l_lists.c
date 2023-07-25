#include "main.h"

/**
 * add_sep_end - add separator node at the end of the list
 * @head: head of list.
 * @sep: separator.
 * Return: address of head.
 */
sep_list *add_sep_end(sep_list **head, char sep)
{
	sep_list *new_node;
	sep_list *temp_node;

	new_node = malloc(sizeof(sep_list));
	if (new_node == NULL)
		return (NULL);

	new_node->separator = sep;
	new_node->next = NULL;
	temp_node = *head;

	if (temp_node == NULL)
		*head = new_node;
	else
	{
		while (temp_node->next != NULL)
			temp_node = temp_node->next;
		temp_node->next = new_node;
	}

	return (*head);
}

/**
 * free_sep_list - free a separator list
 * @head: head of the list.
 * Return: none
 */
void free_sep_list(sep_list **head)
{
	sep_list *temp_node;
	sep_list *curr_node;

	if (head != NULL)
	{
		curr_node = *head;
		while ((temp_node = curr_node) != NULL)
		{
			curr_node = curr_node->next;
			free(temp_node);
		}
		*head = NULL;
	}
}

/**
 * add_line_end - adds the current line at the end of the list.
 * @head: head of the list.
 * @line: current line.
 * Return: address of head.
 */
line_list *add_line_end(line_list **head, char *line)
{
	line_list *new_node, *temp_node;

	new_node = malloc(sizeof(line_list));
	if (new_node == NULL)
		return (NULL);

	new_node->line = line;
	new_node->next = NULL;
	temp_node = *head;

	if (temp_node == NULL)
	{
		*head = new_node;
	}
	else
	{
		while (temp_node->next != NULL)
			temp_node = temp_node->next;
		temp_node->next = new_node;
	}

	return (*head);
}

/**
 * free_line_list - frees the list
 * @head: head of the list.
 * Return: none
 */
void free_line_list(line_list **head)
{
	line_list *temp_node;
	line_list *curr_node;

	if (head != NULL)
	{
		curr_node = *head;
		while ((temp_node = curr_node) != NULL)
		{
			curr_node = curr_node->next;
			free(temp_node);
		}
		*head = NULL;
	}
}
