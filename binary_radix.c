#include "stack.h"

static int calculate_max_bit(t_stack *stack)
{
    int max = 0;
    int bits = 0;

    while (stack)
    {
        if (stack->index > max)
            max = stack->index;
        stack = stack->next;
    }
    while ((max >> bits) != 0)
        bits++;
    return bits;
}

void binary_radix(t_stack **a, t_stack **b)
{
    int a_size;
    int toggle;

    toggle = 0;
    while (toggle < calculate_max_bit(*a))
    {
        a_size = ft_stacksize(*a);
        while (a_size--)
        {
            if (((*a)->index >> toggle) & 1)
                ft_ra(a);
            else
                ft_push(a, b, 'b');
        }
        while (*b)
            ft_push(b, a, 'a');
        toggle++;
        if (check_sorted(*a))
            return ;
    }
}