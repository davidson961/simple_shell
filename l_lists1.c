#include "main.h"

/**
 * add_sep_end - Appends a separator node to the end of a list.
 * @head: The head of the list.
 * @sep: The separator to add.
 * Return: The address of the head.
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
 * sep_list_free - Frees a separator list.
 * @head: The head of the list.
 * Return: None.
 */
void sep_list_free(sep_list **head)
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
 * add_line_end - Appends the current line to the end of the list.
 * @head: The head of the list.
 * @line: The current line to add.
 * Return: The address of the head.
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
 * line_list_free - Frees the linked list.
 * @head: The head of the list.
 * Return: None.
 */
void line_list_free(line_list **head)
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
