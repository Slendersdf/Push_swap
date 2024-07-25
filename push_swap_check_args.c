/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_check_args.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:23:45 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/25 22:58:15 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Convert a String to an int and check for return value errors

static int  ft_atoi(const char *str, int *num)
{
	long	result;
	int    	sign;

	result = 0;
	sign = 1;
	if (*str == '-')
    	sign = -1;
	if (*str == '-' || *str == '+')
    	str++;
	if (!*str)
    	return (0);
	while (*str)
	{
    	if (*str < '0' || *str > '9')
        	return (0);
    	result = result * 10 + (*str - '0');
    	if (result * sign > 2147483647 || result * sign < -2147483648)
        	return (0);
    	str++;
	}
	*num = (int)(result * sign);
	return (1);
}

// Check for duplicates in stack

static int  check_duplicate(t_stack *a, int num)
{
	t_node	*current;
	int    	i;

	if (!a->head)
    	return (0);
	current = a->head;
	i = 0;
	while (i < a->size)
	{
    	if (current->value == num)
        	return (1);
    	current = current->next;
    	i++;
	}
	return (0);
}

// Main check function to check for args, check for duplicates and then add nodes to stack

int parse_args(int argc, char **argv, t_stack *a)
{
	int    	i;
	int    	num;
	t_node	*node;

	i = argc - 1;
	while (i > 0)
	{
    	if (!ft_atoi(argv[i], &num))
        	return (0);
    	if (check_duplicate(a, num))
        	return (0);
    	node = create_node(num);
    	if (!node)
        	return (0);
    	add_node(a, node);
    	i--;
	}
	return (1);
}




