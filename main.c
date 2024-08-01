/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 21:46:49 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/08/01 20:03:24 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialize_stacks(t_stack *a, t_stack *b)
{
	a->head = NULL;
	a->size = 0;
	b->head = NULL;
	b->size = 0;
}

void	handle_error(t_stack *a)
{
	write(2, "Error\n", 6);
	free_stack(a);
}

int	parse_arguments(int argc, char **argv, t_stack *a)
{
	if (argc == 2)
	{
		return (parse_args_string(argv[1], a));
	}
	else
	{
		return (parse_args(argc - 1, argv + 1, a));
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (argc < 2)
		return (0);
	initialize_stacks(&a, &b);
	if (!parse_arguments(argc, argv, &a))
	{
		handle_error(&a);
		return (1);
	}
	if (!is_sorted(&a))
		sort_stack(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
