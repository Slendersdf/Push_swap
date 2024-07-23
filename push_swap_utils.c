#include "push_swap.h"

// Create a new node with a value

t_node  *create_node(int value)
{
	t_node  *node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->prev = node;
	node->next = node;
	return (node);
}

// Add a node to the head of the stack

void	add_node(t_stack *stack, t_node *node)
{
	if (!stack->head)
	{
		stack->head = node;
		node->prev = node;
		node->next = node;
	}
	else
	{
		node->prev = stack->head->prev;
		node->next = stack->head;
		stack->head->prev->next = node;
		stack->head->prev = node;
		stack->head = node;
	}
	stack->size++;
}

// Delete et return the head node of the stack

t_node  *remove_node(t_stack *stack)
{
	t_node  *node;

	if (!stack->head)
		return (NULL);
	node = stack->head; // 1 (5 4 3 2)
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = node->next; // 1 (5 4 3 2) = 5 (4 3 2 1)
		node->prev->next = node->next; // 2 pointe sur 5
		node->next->prev = node->prev; // 5 pointe sur 2
	}
	node->prev = node;
	node->next = node;
	//1 prev et next pointe sur 1
	stack->size--;
	return (node); //On recupere 1 comme si 1 n'avait jamais existe de la liste original
}

// Free the memory of a stack

void	free_stack(t_stack *stack)
{
	t_node  *current;
	t_node  *next;

	if (!stack->head)
		return ;
	current = stack->head;
	while (stack->size > 0)
	{
		next = current->next;
		free(current);
		current = next;
		stack->size--;
	}
	stack->head = NULL;
}

//Function to find the position of the smallest value of a stack

int find_smallest_position(t_stack *stack)
{
	int pos;
	int i;
	t_node *current;
	int min_value;

	pos = 0;
	i = 0;
	current = stack->head;
	min_value = current->value;
	while (i < stack->size)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			pos = i;
		}
		current = current->next;
		i++;
	}
	return (pos);
}

void push_smallest_to_b(t_stack *a, t_stack *b)
{
	int pos = find_smallest_position(a);

	if (pos == 0)
		pb(a, b);
	else if (pos == 1)
	{
		sa(a);
		pb(a, b);
	}
	else if (pos == 2)
	{
		ra(a);
		ra(a);
		pb(a, b);
	}
	else if (pos == 3)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	else if (pos == 4)
	{
		rra(a);
		pb(a, b);
	}
}
