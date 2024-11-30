#include "stack.h"

static int calculate_max_bits(t_stack *stack)
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
// RESOLVER O PROBLEMA COM NÚMEROS NEGATIVOS
// {
//      IMPLEMENTAR INDICES
//      IMPLEMENTAR A NORMALIZAÇÃO (INICIALIZAR COM INDICES RESOLVERÁ O PROBLEMA DOS NEGATIVOS, no mais, é isso)
// }
void binary_radix(t_stack **a, t_stack **b)
{
    int a_size;
    int toggle;
    int operations;
    //int b_size;

    toggle = 0;
    operations = 0;
    //b_size = 0;
    while (toggle < calculate_max_bits(*a))
    {
        a_size = ft_stacksize(*a);
        while (a_size--)
        {
            if (((*a)->index >> toggle) & 1)
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
        }
       // b_size = ft_stacksize(*b);
        while (ft_stacksize(*b))
        {
            ft_pa(b, a);
            operations++;
        }
        toggle++;
        if (check_sorted(*a))
        {
            //printf("%d", operations);
            return ;
        }
    }
    printf("%d", operations);
}