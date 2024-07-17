/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:50:52 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/17 16:17:33 by fpaulas-         ###   ########.fr       */
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
