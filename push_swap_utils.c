/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:25:23 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/30 23:05:44 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Create a new node with a value

t_node	*create_node(int value)
{
	t_node	*node;

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

t_node	*remove_node(t_stack *stack)
{
	t_node	*node;

	if (!stack->head)
		return (NULL);
	node = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = node->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	node->prev = node;
	node->next = node;
	stack->size--;
	return (node);
}

void	add_node_to_end(t_stack *stack, t_node *node)
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
	}
	stack->size++;
}
