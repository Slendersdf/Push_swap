#include "push_swap.h"

void sort_100(t_stack *a, t_stack *b)
{
    int total_chunks = 5;
    int min = find_min(a);
    int max = find_max(a);
    int range = max - min + 1;
    int chunk_range = range / total_chunks;

    for (int i = 0; i < total_chunks; i++)
    {
        int chunk_min = min + i * chunk_range;
        int chunk_max = chunk_min + chunk_range - 1;

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

    while (b->size > 0)
    {
        int max_pos = find_position(b, find_max(b));
        move_to_top(b, max_pos, 'b');
        pa(a, b);
    }
}

int count_in_range(t_stack *stack, int min, int max)
{
    int count = 0;
    t_node *current = stack->head;
    for (int i = 0; i < stack->size; i++)
    {
        if (current->value >= min && current->value <= max)
            count++;
        current = current->next;
    }
    return count;
}

int     find_max(t_stack *stack)
{
   t_node   *current;
   int      max;
   int      i;


   i = 0;
   current = stack->head;
   max = current->value;
   while (i < stack->size)
   {
       if (current->value > max)
           max = current->value;
       current = current->next;
       i++;
   }
   return (max);
}

