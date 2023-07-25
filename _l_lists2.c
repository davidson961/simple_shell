#include "main.h"

/**
 * add_var_end - adds a variable node at the end of the list
 * @head: head of the list.
 * @var_len: length of variable.
 * @value: value of variable.
 * @val_len: length of value.
 * Return: address of head.
 */
r_var *add_var_end(r_var **head, int var_len, char *value, int val_len)
{
	r_var *new_node, *temp_node;

	new_node = malloc(sizeof(r_var));
	if (new_node == NULL)
		return (NULL);
	new_node->var_len = var_len;
	new_node->value = value;
	new_node->val_len = val_len;
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
 * free_var_list - frees the var list
 * @head: head of the list.
 * Return: None.
 */
void free_var_list(r_var **head)
{
	r_var *temp_node;
	r_var *curr_node;

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
