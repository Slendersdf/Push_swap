/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 22:31:29 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/08/01 20:38:12 by fpaulas-         ###   ########.fr       */
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
	int	half_size;

	moves = pos;
	half_size = stack->size / 2;
	if (pos > half_size)
		moves = stack->size - pos;
	while (moves > 0)
	{
		if (pos <= half_size)
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

int	count_in_range(t_stack *stack, int min, int max)
{
	int		i;
	int		count;
	t_node	*current;

	i = 0;
	count = 0;
	current = stack->head;
	while (i < stack->size)
	{
		if (current->value >= min && current->value <= max)
			count++;
		current = current->next;
		i++;
	}
	return (count);
}
