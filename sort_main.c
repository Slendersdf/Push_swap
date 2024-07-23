#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack)
{
	t_node	*current = stack->head;
	int	i = 0;

	if (current == NULL)
	{
		printf("Stack is empty\n");
		return ;
	}
	while (i < stack->size)
	{
		printf("%d ", current->value);
		current = current->next;
		i++;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	a;
	t_stack b;
	t_node	*node1 = create_node(1);
	t_node	*node2 = create_node(2);
	t_node	*node3 = create_node(3);
	t_node	*node4 = create_node(4);
	t_node	*node5 = create_node(5);

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;

	add_node(&a, node1);
	add_node(&a, node2);
	add_node(&a, node3);
	//three_sort
	add_node(&a, node4);
	add_node(&a, node5);
	//five sort

	/* printf("Stack A before sorting by sort_three function: ");
	print_stack(&a);

	sort_three(&a);

	if (is_sorted(&a) == 1)
	{
		printf("Stack A sorted successfully\n");
		print_stack(&a);
	}
	else
		printf("Stack A sort failed"); */

	printf("Stack A before sorting by sort_five function: ");
	print_stack(&a);

	sort_five(&a, &b);

	if (is_sorted(&a) == 1)
	{
		printf("Stack A sorted successfully\n");
		print_stack(&a);
	}
	else
	{
		printf("Stack A sort failed\n");
		print_stack(&a);
	}
	free_stack(&a);
}
