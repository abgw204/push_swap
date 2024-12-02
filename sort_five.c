#include "stack.h"

static void five_sort(t_stack **a, t_stack **b, t_stack *temp)
{
    while (ft_stacksize(*b) != 2)
    {
        if (temp->is_min || temp->is_max)
            ft_push(a, b, 'b');
        else
            ft_ra(a);
        temp = *a;
    }
    sort_three(a);
    if (check_sorted(*b))
        ft_swap(b, 'b');
}
void sort_five(t_stack **a, t_stack **b)
{
    t_stack *temp;

    is_min(*a);
    is_max(*a);
    temp = *a;

    five_sort(a, b, temp);
    ft_push(b, a, 'a');
    ft_ra(a);
    ft_push(b, a, 'a');
}