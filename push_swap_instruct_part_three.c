/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct_part_three.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:51:48 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/21 21:52:11 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *a)
{
	if (a->size < 2)
		return ;
	a->head = a->head->next;
	write(1, "ra\n", 3);
}

void	rb(t_stack *b)
{
	if (b->size < 2)
		return ;
	b->head = b->head->next;
	write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}
