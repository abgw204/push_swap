#include "stack.h"
/*  swap a = sa
    swap b = sb
    swap a and b = ss
    push a = pa | DONE
    push b = pb | DONE
    rotate a = ra
    rotate b = rb
    rotate and b = rr
    reverse rotate a = rra
    reverse rotate b = rrb
    reverse rotate a and b = rrr
*/

void ft_sa(t_stack **a)
{
    t_stack *temp;
    t_stack *third_node;

    if (ft_stacksize(*a) > 2)
    {
      third_node = (*a)->next->next;
      temp = (*a)->next;
      third_node->prev = *a;
      temp->next = *a;
      (*a)->prev = temp;
      (*a)->next = third_node;
      temp->prev = NULL;
    }
    write(1, "sa\n", 3);
}

// Empurra 1 node do stack A para o stack B

void ft_pa(t_stack **stack1, t_stack **stack2)
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
  else
  {
    temp = (*stack1)->next;
    (*stack1)->next = NULL;
    ft_lstadd_front(stack2, stack1);
    *stack1 = temp;
  }
}

// Empurra 1 node do stack B para o stack A

void ft_pb(t_stack **stack1, t_stack **stack2)
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
  else
  {
    temp = (*stack1)->next;
    (*stack1)->next = NULL;
    ft_lstadd_front(stack2, stack1);
    *stack1 = temp;
  }
}

// Essa função printa os dois stacks levando em consideração
// seus tamanhos, para sempre printar em forma de tabela.
// Basta calcular a diferença do tamanho dos stacks,
// e caso stack A seja maior que stack B, printar stack A
// até essa diferença, e depois printar até o tamanho total de stack A,
// ou vice-versa.
// Se forem do mesmo tamanho, basta printar enquanto for i for menor
// que stack A ou B, tanto faz (isso está no else).

void print_stacks(t_stack *a, t_stack *b)
{
  int a_size = ft_stacksize(a);
  int b_size = ft_stacksize(b);
  int diff_size = 0;
  int i = 0;
  if (a_size > b_size)
    diff_size = a_size - b_size;
  else
    diff_size = b_size - a_size;

  printf("Stack A size: %d\n", a_size);
  printf("\nStack B size: %d\n\n", b_size);
  printf("A   B:\n\n");

  if (!a || !b)
  {
    if (a && !b)
    {
      while (i < a_size)
      {
        printf("%d\n", a->nbr);
        a = a->next;
        i++;
      }
    }
    else if (b && !a)
    {
      while (i < b_size)
      {
        printf("    %d\n", b->nbr);
        b = b->next;
        i++;
      }
    }
    return ;
  }
  

  if (a_size > b_size)
  {
    while (i < diff_size)
    {
      printf("%d\n", a->nbr);
      a = a->next;
      i++;
    }
    while (i < a_size)
    {
      printf("%d   %d\n", a->nbr, b->nbr);
      a = a->next;
      b = b->next;
      i++;
    }
  }
  else if (b_size > a_size)
  {
    while (i < diff_size)
    {
      printf("    %d\n", b->nbr);
      b = b->next;
      i++;
    }
    while (i < b_size)
    {
      printf("%d   %d\n", a->nbr, b->nbr);
      a = a->next;
      b = b->next;
      i++;
    }
  }
  else
  {
    while (i < a_size)
    {
      printf("%d   %d\n", a->nbr, b->nbr);
      a = a->next;
      b = b->next;
      i++;
    }
  }

}

int main()
{
  t_stack *a = NULL;
  t_stack *b = NULL;

  ft_stackadd_back(&a, ft_stacknew(3));
  ft_stackadd_back(&a, ft_stacknew(5));
  ft_stackadd_back(&a, ft_stacknew(4));
  ft_stackadd_back(&a, ft_stacknew(9));
  ft_stackadd_back(&a, ft_stacknew(8));
  ft_stackadd_back(&a, ft_stacknew(7));

  /*ft_stackadd_back(&b, ft_stacknew(9));
  ft_stackadd_back(&b, ft_stacknew(8));
  ft_stackadd_back(&b, ft_stacknew(7));
  ft_stackadd_back(&b, ft_stacknew(6));*/

  ft_sa(&a);
  print_stacks(a, b);
  exit(1);
  printf("\npb pb\n\n");
  ft_pa(&b, &a);
  ft_pa(&b, &a);

  print_stacks(a, b);

  printf("\npb pb\n\n");
  ft_pb(&b, &a);
  ft_pb(&b, &a);

  print_stacks(a, b);

  ft_free(&a);
  ft_free(&b);
  exit(0);
}