/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_prototype.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 16:03:55 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/08/01 19:23:55 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->head->next->next->value;
	if (first > second && first < third && second < third)
		sa(a);
	else if (first > second && second > third)
	{
		sa(a);
		rra(a);
	}
	else if (first > second && first > third && second < third)
		ra(a);
	else if (first < second && first < third && second > third)
	{
		sa(a);
		ra(a);
	}
	else if (first < second && first > third && second > third)
		rra(a);
}

void	sort_nine(t_stack *a, t_stack *b)
{
	int	min;
	int	pos;

	while (a->size > 3)
	{
		min = find_min(a);
		pos = find_position(a, min);
		move_to_top(a, pos, 'a');
		pb(a, b);
	}
	sort_three(a);
	while (b->size > 0)
		pa(a, b);
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (a->size == 2 && a->head->value > a->head->next->value)
		sa(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_nine(a, b);
	else if (a->size <= 100)
		sort_100(a, b);
	else if (a->size <= 500)
		sort_500(a, b);
}
