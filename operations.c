#include "stack.h"
/*  swap a = sa
    swap b = sb
    swap a and b = ss
    push a = pa
    push b = pb
    rotate a = ra
    rotate b = rb
    rotate and b = rr
    reverse rotate a = rra
    reverse rotate b = rrb
    reverse rotate a and b = rrr
*/
void ft_sa(t_stack **stack_a)
{
    t_stack *temp;
    t_stack *full_list;

    //if (!*stack_a || !(*stack_a)->next)
      //  return ;
    temp = (*stack_a);
    temp = temp->next->next;
    full_list = (*stack_a);
    (*stack_a) = (*stack_a)->next;
    (*stack_a)->next = full_list;
    (*stack_a)->next->next = temp;
    write(1, "sa\n", 3);
}