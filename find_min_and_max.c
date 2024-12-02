#include "stack.h"

t_stack *find_min_and_next(t_stack *stack_a)
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

void is_min(t_stack *stack_a)
{
    long    min;
    t_stack *min_node;

    if (!stack_a)
        return ;
    min = 2147483649;
    while (stack_a)
    {
        if (stack_a->index < min)
        {
            min = stack_a->index;
            min_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    min_node->is_min = true;
}

void is_max(t_stack *stack_a)
{
    long    max;
    t_stack *max_node;

    if (!stack_a)
        return ;
    max = -2147483649;
    while (stack_a)
    {
        if (stack_a->index > max)
        {
            max = stack_a->index;
            max_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    max_node->is_max = true;
}

t_stack *find_max(t_stack *stack_a)
{
    long    max;
    t_stack *max_node;

    if (!stack_a)
        return NULL;
    max = -2147483649;
    while (stack_a)
    {
        if (stack_a->index > max)
        {
            max = stack_a->index;
            max_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    return (max_node);
}

t_stack *find_min(t_stack *stack_a)
{
    long    min;
    t_stack *min_node;

    if (!stack_a)
        return NULL;
    min = 2147483649;
    while (stack_a)
    {
        if (stack_a->nbr < min)
        {
            min = stack_a->nbr;
            min_node = stack_a;
        }
        stack_a = stack_a->next;
    }
    return (min_node);
}