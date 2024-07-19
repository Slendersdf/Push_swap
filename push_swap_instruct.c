/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_instruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:50:52 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/19 19:44:06 by fpaulas-         ###   ########.fr       */
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
