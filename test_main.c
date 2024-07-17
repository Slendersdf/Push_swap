#include "push_swap.h"
#include <stdio.h>

#include "push_swap.h"
#include <stdio.h>

void print_stack(t_stack *stack)
{
	t_node *current = stack->head;
	int i = 0;

	if (!current)
	{
		printf("Stack is empty\n");
		return;
	}

	while (i < stack->size)
	{
		printf("%d ", current->value);
		current = current->next;
		i++;
	}
	printf("\n");
}

void test_sa()
{
	t_stack a;
	t_node *node1 = create_node(1);
	t_node *node2 = create_node(2);

	a.head = NULL;
	a.size = 0;

	add_node(&a, node1);
	add_node(&a, node2);

	printf("Stack A before sa: ");
	print_stack(&a);

	sa(&a);

	printf("Stack A after sa: ");
	print_stack(&a);

	free_stack(&a);
}

void test_sb()
{
	t_stack b;
	t_node *node1 = create_node(3);
	t_node *node2 = create_node(4);

	b.head = NULL;
	b.size = 0;

	add_node(&b, node1);
	add_node(&b, node2);

	printf("Stack B before sb: ");
	print_stack(&b);

	sb(&b);

	printf("Stack B after sb: ");
	print_stack(&b);

	free_stack(&b);
}

void test_ss()
{
	t_stack a;
	t_stack b;
	t_node *node1 = create_node(1);
	t_node *node2 = create_node(2);
	t_node *node3 = create_node(3);
	t_node *node4 = create_node(4);

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;

	add_node(&a, node1);
	add_node(&a, node2);
	add_node(&b, node3);
	add_node(&b, node4);

	printf("Stack A before ss: ");
	print_stack(&a);
	printf("Stack B before ss: ");
	print_stack(&b);

	ss(&a, &b);

	printf("Stack A after ss: ");
	print_stack(&a);
	printf("Stack B after ss: ");
	print_stack(&b);

	free_stack(&a);
	free_stack(&b);
}

int main()
{
	printf("Testing sa function:\n");
	test_sa();
	printf("\n");

	printf("Testing sb function:\n");
	test_sb();
	printf("\n");

	printf("Testing ss function:\n");
	test_ss();
	printf("\n");

	return 0;
}
