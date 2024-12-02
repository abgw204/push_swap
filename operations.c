#include "stack.h"
#include <stdio.h>
/*  swap a = sa | DONE
    swap b = sb | DONE
    swap a and b = ss | DONE
    push a = pa | DONE
    push b = pb | DONE
    rotate a = ra | DONE
    rotate b = rb | DONE
    rotate and b = rr | DONE
    reverse rotate a = rra | DONE
    reverse rotate b = rrb | DONE
    reverse rotate a and b = rrr | DONE
*/

// Faz um swap nos dois primeiros nodes do stack A

void ft_swap(t_stack **a, char a_b)
{
    t_stack *temp;

    temp = (*a)->next;
    (*a)->next = temp->next;
    (*a)->prev = temp;
    temp->next = *a;
    temp->prev = NULL;
    *a = temp;
    if (a_b == 'a')
      write(1, "sa\n", 3);
    else
      write(1, "sb\n", 3);
}

static void push_util(t_stack **stack1, t_stack **stack2)
{
  ft_stackadd_front(stack2, stack1);
  *stack1 = NULL;
}

void ft_push(t_stack **stack1, t_stack **stack2, char a_b)
{
  t_stack *temp;

  if (!*stack2)
  {
    temp = (*stack1)->next;
    (*stack1)->next = NULL;
    ft_stackadd_back(stack2, *stack1);
    *stack1 = temp;
    (*stack1)->prev = NULL;
  }
  else if ((*stack1)->next)
  {
    temp = (*stack1)->next;
    temp->prev = NULL;
    (*stack1)->next = NULL;
    ft_stackadd_front(stack2, stack1);
    *stack1 = temp;
  }
  else
    push_util(stack1, stack2);
  if (a_b == 'b')
    write(1, "pb\n", 3);
  else
    write(1, "pa\n", 3);
}

void ft_ra(t_stack **a)
{
  t_stack *temp;
  t_stack *last_node;

  if (ft_stacksize(*a) == 1)
    return ;
  temp = (*a)->next;
  temp->prev = NULL;
  last_node = ft_stacklast(*a);
  last_node->next = *a;
  (*a)->prev = last_node;
  (*a)->next = NULL;
  *a = temp;
  write(1, "ra\n", 3);
}

void ft_rb(t_stack **b)
{
  t_stack *temp;
  t_stack *last_node;

  if (ft_stacksize(*b) == 1)
    return ;
  temp = (*b)->next;
  temp->prev = NULL;
  last_node = ft_stacklast(*b);
  last_node->next = *b;
  (*b)->prev = last_node;
  (*b)->next = NULL;
  *b = temp;
  write(1, "rb\n", 3);
}

void ft_rra(t_stack **a)
{
  t_stack *last_node;

  last_node = ft_stacklast(*a);
  last_node->prev->next = NULL;
  last_node->prev = NULL;
  last_node->next = *a;
  (*a)->prev = last_node;
  *a = last_node;
  write(1, "rra\n", 4);
}