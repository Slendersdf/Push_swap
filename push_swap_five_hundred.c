#include "push_swap.h"

void    sort_500(t_stack *a, t_stack *b)
{
    int i;
    int min;
    int pos;

    while (a->size > 0)
    {
        i = 0;
        min = find_min(a);
        pos = find_position(a, min);
        move_to_top(a, pos, 'a');
        pb(a, b);
        i++;
        if (i == 50)
        {
            sort_50(a, b);
            i = 0;
        }
    }
    while (b->size > 0)
    {
        min = find_max(b);
        pos = find_position(b, min);
        move_to_top(b, pos, 'b');
        pa(a, b);
    }
}

void    sort_50(t_stack *a, t_stack *b)
{
    int min;
    int pos;

    while (a->size > 0)
    {
        min = find_min(a);
        pos = find_position(a, min);
        move_to_top(a, pos, 'a');
        pb(a, b);
    }
    while (b->size > 0)
    {
        min = find_min(b);
        pos = find_position(b, min);
        move_to_top(b, pos, 'b');
        pa(a, b);
    }
}
