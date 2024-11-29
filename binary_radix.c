#include "stack.h"

int reverse_radix(t_stack **b, int toggle)
{
    int bit;

    bit = (*b)->nbr >> (toggle + 1) & 1;
    if (bit == 1)
        return (1);
    return (0);
}

void binary_radix(t_stack **a, t_stack **b)
{
    int a_size;
    int toggle;
    int operations;
    int b_size;

    toggle = 0;
    operations = 0;
    while (toggle < 32)
    {
        a_size = ft_stacksize(*a);
        while (a_size)
        {
            if (((*a)->nbr >> toggle) & 1)
            {
                ft_ra(a);
                operations++;
            }
            else
            {
                ft_pb(a, b);
                operations++;
                //print_stacks(*a, *b);
            }
            if (!a_size)
                break ;
            a_size--;
        }
        b_size = ft_stacksize(*b);
        while (b_size)
        {
            if (((*b)->nbr >> (toggle + 1) & 1) == 1)
                ft_pa(b, a);
            else
                ft_rb(b);
            b_size--;
        }
        while (*b)
            ft_pa(b, a);
        toggle++;
        if (check_sorted(*a))
        {
            printf("%d", operations);
            return ;
        }
    }
}