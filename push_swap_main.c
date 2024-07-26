/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:47:41 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/26 06:56:53 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Main function that creates stacks and check args then sort it

int main(int argc, char **argv)
{
    t_stack a;
    t_stack b;

    if (argc == 2)
    {
        a.head = NULL;
        a.size = 0;
        b.head = NULL;
        b.size = 0;
        if (!parse_args_string(argv[1], &a))
        {
            write(2, "Error\n", 6);
            free_stack(&a);
            return (1);
        }
    }
    else if (argc < 2)
        return (0);
    else
    {
        a.head = NULL;
        a.size = 0;
        b.head = NULL;
        b.size = 0;
        if (!parse_args(argc - 1, argv + 1, &a))
        {
            write(2, "Error\n", 6);
            free_stack(&a);
            return (1);
        }
    }
    if (!is_sorted(&a))
        sort_stack(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}

