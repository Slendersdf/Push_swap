/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct_part_one.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:50:52 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/21 21:51:45 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *a)
{
	int tmp;

	if (a->size < 2)
	return ;
	tmp = a->head->value;
	a->head->value = a->head->next->value;
	a->head->next->value = tmp;
	write(1, "sa\n", 3);
}

void	sb(t_stack *b)
{
	int tmp;

	if (b->size < 2)
	return ;
	tmp = b->head->value;
	b->head->value = b->head->next->value;
	b->head->next->value = tmp;
	write(1, "sb\n", 3);
}

// Function that exchange the position of the first two element of stack a and b

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}

