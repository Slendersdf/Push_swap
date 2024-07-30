/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_utils_two.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:37:08 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/30 22:41:30 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	find_max(t_stack *stack)
{
	t_node	*current;
	int		max;
	int		i;

	i = 0;
	current = stack->head;
	max = current->value;
	while (i < stack->size)
	{
		if (current->value > max)
			max = current->value;
		current = current->next;
		i++;
	}
	return (max);
}
