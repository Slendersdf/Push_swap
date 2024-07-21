/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct_part_two.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:46:47 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/21 21:52:16 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Functon that moves the first element of stack b and put it at the top of a

void	pa(t_stack *a, t_stack *b)
{
	t_node *node;

	if (b->size == 0)
		return ;
	node = remove_node(b);
	add_node(a, node);
	write(1, "pa\n", 3);
}

void	pb(t_stack *a, t_stack *b)
{
	t_node *node;

	if (a->size == 0)
		return ;
	node = remove_node(a);
	add_node(b, node);
	write(1, "pb\n", 3);
}
