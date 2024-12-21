#include "nome_do_seu_header.h"
#include <stdio.h>

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
  printf("\nA   B:\n\n");

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

  ft_stackadd_back(&a, ft_stacknew(0));
  ft_stackadd_back(&a, ft_stacknew(1));
  ft_stackadd_back(&a, ft_stacknew(2));
  ft_stackadd_back(&a, ft_stacknew(3));
  ft_stackadd_back(&a, ft_stacknew(4));
  ft_stackadd_back(&a, ft_stacknew(5));
  ft_stackadd_back(&a, ft_stacknew(6));

  ft_stackadd_back(&b, ft_stacknew(9));
  ft_stackadd_back(&b, ft_stacknew(8));
  ft_stackadd_back(&b, ft_stacknew(7));
  ft_stackadd_back(&b, ft_stacknew(6));
  ft_stackadd_back(&a, ft_stacknew(8));
  ft_stackadd_back(&a, ft_stacknew(7));
 
  print_stacks(a, b);

  ft_free(&a);
  ft_free(&b);
}
