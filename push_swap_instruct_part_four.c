/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct_part_four.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:52:24 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/21 22:08:09 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *a)
{
	if (a->size <= 1)
		return ;
	a->head = a->head->prev;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *b)
{
	if (b->size <= 1)
		return ;
	b->head = b->head->prev;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 4);
}
