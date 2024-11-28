#include "stack.h"
void binary_radix(t_stack **a, t_stack **b, int a_size)
{
    int size_before;
    int bit;
    int pushes;
    int toggle;
    int operations;

    bit = 0;
    size_before = a_size;
    pushes = 0;
    toggle = 0;
    operations = 0;
    while (1)
    {
        a_size = size_before;
        while (a_size)
        {
            bit = (*a)->nbr >> toggle & 1;
            if (bit == 1)
            {
                ft_ra(a);
                //print_stacks(*a, *b);
                operations++;
                a_size--;
                if (!*b)
                {
                    if (check_sorted(*a))
                        return ;
                }
            }
            else
            {
                ft_pb(a, b);
                operations++;
                //print_stacks(*a, *b);
                pushes++;
                a_size--;
            }
            if (!a_size)
                break ;
        }
        while (pushes > 0)
        {
            ft_pa(b, a);
            pushes--;
            operations++;
            //print_stacks(*a, *b);
        }
        toggle++;
        if (check_sorted(*a))
        {
            printf("%d", operations);
            return ;
        }
    }
}