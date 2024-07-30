/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 23:05:13 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/30 23:05:47 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Free the memory of a stack

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next;

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

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
