#include "stack.h"

t_stack *find_min(t_stack *stack_a)
{
    long    min;
    t_stack *min_node;

    if (!stack_a)
        return NULL;
    min = 2147483649;
    while (stack_a)
    {
        if (stack_a->nbr < min && stack_a->have_index == false)
        {
            min = stack_a->nbr;
            min_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    min_node->have_index = true;
    return (min_node);
}

t_stack *find_max(t_stack *stack_a)
{
    long    max;
    t_stack *max_node;

    if (!stack_a)
        return NULL;
    max = 0;
    while (stack_a)
    {
        if (stack_a->nbr > max)
        {
            max = stack_a->nbr;
            max_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    return (max_node);
}