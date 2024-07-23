/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpaulas- <fpaulas-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 15:49:38 by fpaulas-          #+#    #+#             */
/*   Updated: 2024/07/23 23:47:54 by fpaulas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_stack
{
	t_node	*head;
	int		size;
}				t_stack;

// Stack operations
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);

// Node helper functions
t_node	*create_node(int value);
void	add_node(t_stack *stack, t_node *node);
t_node	*remove_node(t_stack *stack);
void	free_stack(t_stack *stack);

// Sort helper functions
int	is_sorted(t_stack *a);
int	find_min(t_stack *stack);
int	find_position(t_stack *stack, int value);
void	move_to_top(t_stack *stack, int pos, char stack_name);

int find_smallest_position(t_stack *stack);
void push_smallest_to_b(t_stack *a, t_stack *b);

// Parsing and error handling
int	 parse_args(int argc, char **argv, t_stack *a);

// Tempo Sorting functions
void	sort_three(t_stack *a);
void	sort_five(t_stack *a, t_stack *b);
void	sort_stack(t_stack *a, t_stack *b);

#endif
