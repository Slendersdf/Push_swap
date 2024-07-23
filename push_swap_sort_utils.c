/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:31:29 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/23 23:37:24 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function to check if a stack is already sorted

int	is_sorted(t_stack *a)
{
	t_node	*current;
	int		i;

	i = 0;
	if (a->size < 2)
		return (1);
	current = a->head;
	while (i < a->size - 1)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
		i++;
	}
	return (1);
}

// Function that finds the minimum value of a stack

int	find_min(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		i;

	i = 0;
	current = stack->head;
	min = current->value;

	while (i < stack->size)
	{
		if (current->value < min)
			min = current->value;
		current = current->next;
		i++;
	}
	return (min);
}

int	find_position(t_stack *stack, int value)
{
	t_node	*current;
	int		pos;

	current = stack->head;
	pos = 0;
	while (pos < stack->size)
	{
		if (current->value == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	move_to_top(t_stack *stack, int pos, char stack_name)
{
	int	moves;

	moves = pos;
	if (moves > stack->size / 2)
		moves = stack->size - moves;
	while (moves > 0)
	{
		if (pos <= stack->size / 2)
		{
			if (stack_name == 'a')
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (stack_name == 'a')
				rra(stack);
			else
				rrb(stack);
		}
		moves--;
	}
}
