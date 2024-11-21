#include <stdio.h>
#include "stack.h"

void ft_sort(t_stack **stack_a)
{
    if (ft_stacksize(*stack_a) == 2)
        ft_sa(stack_a);
}

static void init_stack_a(t_stack **stack_a, char *argv[])
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        j = atoi2(argv[i]);
        ft_stackadd_back(stack_a, ft_stacknew(j));
        i++;
    }
    printf("%d\n", (*stack_a)->nbr);
    printf("%d\n", (*stack_a)->next->nbr);
    printf("%d\n", (*stack_a)->next->next->nbr);
    exit(1);
    if (!stack_a || check_duplicate(*stack_a))
    {
        ft_free(stack_a);
        ft_error(2);
    }
}
int main(int argc, char *argv[])
{
    t_stack *stack_a;
    //t_stack *stack_b;

    stack_a = NULL;
    //stack_b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        ft_error(0);
    else if (argc == 2)
        argv = ft_split(argv[1], ' ');
    else if (argc > 2)
        init_stack_a(&stack_a, argv + 1);
    ft_sort(&stack_a);
    exit(1);
    /* while (stack_a)
    {
        printf("%ld, ", stack_a->nbr);
        stack_a = stack_a->next;
        if (!stack_a->next)
        {
            printf("%ld", stack_a->nbr);
            stack_a = stack_a->next;
        }
    }
    */
    ft_free(&stack_a);
    exit(1);
}