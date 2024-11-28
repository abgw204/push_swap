#include "stack.h"

void ft_sort(t_stack **a, t_stack **b)
{
    int a_size = ft_stacksize(*a);
    if (!check_sorted(*a))
    {
        if (a_size == 2)
        {
            ft_sa(a);
            exit(0);
        }
        else if (a_size == 3)
            sort_three(a);
        else
        {
            binary_radix(a, b, a_size);
        }
    }
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
    if (!stack_a || check_duplicate(*stack_a))
    {
        ft_free(stack_a);
        ft_error(2);
    }
}
int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;

    if (argc == 1 || (argc == 2 && !argv[1][0]))
        ft_error(0);
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        init_stack_a(&a, argv);
    }
    else
        init_stack_a(&a, argv + 1);
    ft_sort(&a, &b);
    print_stacks(a, b);
    ft_free(&a);
}