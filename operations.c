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

void ft_push(t_stack **a, t_stack **b)
{
  t_stack *temp = NULL;

  if (!*b)
  {
    temp = (*a)->next;
    (*a)->next = NULL;
    ft_stackadd_back(b, *a);
    *a = temp;
    (*a)->prev = NULL;
  }
  else
    ft_lstadd_front(b, *a);
}

int main()
{
  t_stack *a = NULL;
  t_stack *b = NULL;

  ft_stackadd_back(&a, ft_stacknew(3));
  ft_stackadd_back(&a, ft_stacknew(5));
  ft_stackadd_back(&a, ft_stacknew(7));

  for (int i = 0; i < 3; i++)
  {
    printf("%d\n", a->nbr);
    a = a->next;
  }
  ft_push(&a, &b);
  //exit(1);
  //ft_push(&a, &b);
  printf("%d\n", b->nbr);
    //b = b->next;
    //printf("%d\n", b->nbr);
}