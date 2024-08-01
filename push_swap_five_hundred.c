/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_five_hundred.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 20:13:29 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/08/01 20:38:45 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_500(t_stack *a, t_stack *b)
{
	int	total_chunks;
	int	range;
	int	chunk_range;
	int	min;
	int	i;

	total_chunks = 10;
	min = find_min(a);
	range = find_max(a) - find_min(a) + 1;
	chunk_range = range / total_chunks;
	i = 0;
	while (i < total_chunks)
	{
		process_chunk(a, b, min + i * chunk_range, chunk_range);
		i++;
	}
	sort_remaining(a);
	sort_b_stack(a, b);
}
