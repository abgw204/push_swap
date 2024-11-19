#include "stack.h"

bool check_sorted(t_stack *stack_a)
{
    while (stack_a->next)
    {
        if (stack_a->nbr > stack_a->next->nbr)
            return (false);
        stack_a = stack_a->next;
    }
    return (true);
}