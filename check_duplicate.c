#include "stack.h"
int check_duplicate(t_stack *stack_a)
{
    t_stack *next;

    while (stack_a)
    {
        next = stack_a->next;
        while (next)
        {
             if (stack_a->nbr == next->nbr)
                return (1);
            next = next->next;
        }
        stack_a = stack_a->next;
    }
    return (0);
}