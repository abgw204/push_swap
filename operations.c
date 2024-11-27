#include "stack.h"
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

void ft_sa(t_stack **a)
{
    t_stack *temp;

    temp = (*a)->next;
    (*a)->next = temp->next;
    (*a)->prev = temp;
    temp->next = *a;
    temp->prev = NULL;
    *a = temp;
    write(1, "sa\n", 3);
}

// Faz um swap nos dois primeiros nodes do stack B

void ft_sb(t_stack **b)
{
    t_stack *temp;

    temp = (*b)->next;
    (*b)->next = temp->next;
    (*b)->prev = temp;
    temp->next = *b;
    temp->prev = NULL;
    *b = temp;
    write(1, "sb\n", 3);
}

// Faz um swap nos dois primeiros nodes do stack A e nos dois primeiros
// nodes do stack B

void ft_ss(t_stack **a, t_stack **b)
{
  ft_sa(a);
  ft_sb(b);
  write(1, "ss\n", 3);
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
    ft_stackadd_front(stack2, stack1);
    *stack1 = temp;
  }
  write(1, "pa\n", 3);
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
    ft_stackadd_front(stack2, stack1);
    *stack1 = temp;
  }
  write(1, "pb\n", 3);
}

// Manda o primeiro elemento da pilha A para baixo,
// empurrando todos os outros para cima.

void ft_ra(t_stack **a)
{
  t_stack *temp;
  t_stack *last_node;

  temp = (*a)->next;
  temp->prev = NULL;
  last_node = ft_stacklast(*a);
  last_node->next = *a;
  (*a)->prev = last_node;
  (*a)->next = NULL;
  *a = temp;
  write(1, "ra\n", 3);
}

// Manda o primeiro elemento da pilha B para baixo,
// empurrando todos os outros para cima.

void ft_rb(t_stack **b)
{
  t_stack *temp;
  t_stack *last_node;

  temp = (*b)->next;
  temp->prev = NULL;
  last_node = ft_stacklast(*b);
  last_node->next = *b;
  (*b)->prev = last_node;
  (*b)->next = NULL;
  *b = temp;
  write(1, "rb\n", 3);
}

// Manda o primeiro elemento da pilha A e da pilha B para baixo,
// empurrando todos os outros para cima.

void ft_rr(t_stack **a, t_stack **b)
{
  ft_ra(a);
  ft_rb(b);
  write(1, "rr\n", 3);
}

// Manda o último elemento da pilha A para cima,
// empurrando todos os outros para baixo.

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

void ft_rrb(t_stack **b)
{
  t_stack *last_node;

  last_node = ft_stacklast(*b);
  last_node->prev->next = NULL;
  last_node->prev = NULL;
  last_node->next = *b;
  (*b)->prev = last_node;
  *b = last_node;
  write(1, "rrb\n", 4);
}

void ft_rrr(t_stack **a, t_stack **b)
{
  ft_rra(a);
  ft_rrb(b);
  write(1, "rrr\n", 4);
}

// Essa função printa os dois stacks levando em consideração
// seus tamanhos, para sempre printar em forma de tabela.
// Basta calcular a diferença do tamanho dos stacks,
// e caso stack A seja maior que stack B, printar stack A
// até essa diferença, e depois printar até o tamanho total de stack A,
// ou vice-versa.
// Se forem do mesmo tamanho, basta printar enquanto i for menor
// que stack A ou B, tanto faz (isso está no else).

void print_stacks(t_stack *a, t_stack *b)
{
  int a_size = ft_stacksize(a);
  int b_size = ft_stacksize(b);
  int diff_size = a_size > b_size ? (a_size - b_size) : (b_size - a_size);
  int i = 0;

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

/*int main()
{
  t_stack *a = NULL;
  t_stack *b = NULL;

  ft_stackadd_back(&a, ft_stacknew(0));
  ft_stackadd_back(&a, ft_stacknew(1));
  ft_stackadd_back(&a, ft_stacknew(2));
  ft_stackadd_back(&a, ft_stacknew(3));
  ft_stackadd_back(&a, ft_stacknew(4));
  ft_stackadd_back(&a, ft_stacknew(5));
  ft_stackadd_back(&a, ft_stacknew(6));
  ft_stackadd_back(&a, ft_stacknew(7));
  ft_stackadd_back(&a, ft_stacknew(8));
  ft_stackadd_back(&a, ft_stacknew(9));

  ft_stackadd_back(&b, ft_stacknew(9));
  ft_stackadd_back(&b, ft_stacknew(8));
  ft_stackadd_back(&b, ft_stacknew(7));
  ft_stackadd_back(&b, ft_stacknew(6));
  ft_stackadd_back(&a, ft_stacknew(8));
  ft_stackadd_back(&a, ft_stacknew(7));
 
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  ft_ra(&a);
  print_stacks(a, b);
  printf("\n\n");
  int t = 97;
  int pos = 0;
  while (pos <= 7)
  {
    int bit = (t >> pos++) & 1;
    printf("%d", bit);
  }

  ft_free(&a);
  ft_free(&b);
}*/