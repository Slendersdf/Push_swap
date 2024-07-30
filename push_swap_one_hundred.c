/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_one_hundred.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:17:01 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/30 22:41:46 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_100(t_stack *a, t_stack *b)
{
	int	total_chunks;
	int	range;
	int	chunk_range;
	int	min;
	int	i;

	total_chunks = 5;
	min = find_min(a);
	range = find_max(a) - find_min(a) + 1;
	chunk_range = range / total_chunks;
	i = 0;
	while (i < total_chunks)
	{
		process_chunk(a, b, min + i * chunk_range, chunk_range);
		i++;
	}
	sort_b_stack(a, b);
}

void	process_chunk(t_stack *a, t_stack *b, int chunk_min, int chunk_range)
{
	int	chunk_max;

	chunk_max = chunk_min + chunk_range - 1;
	while (a->size > 0 && count_in_range(a, chunk_min, chunk_max) > 0)
	{
		if (a->head->value >= chunk_min && a->head->value <= chunk_max)
		{
			pb(a, b);
			if (b->head->value < chunk_min + chunk_range / 2)
				rb(b);
		}
		else
			ra(a);
	}
}

void	sort_b_stack(t_stack *a, t_stack *b)
{
	int	max_pos;

	max_pos = 0;
	while (b->size > 0)
	{
		max_pos = find_position(b, find_max(b));
		move_to_top(b, max_pos, 'b');
		pa(a, b);
	}
}
