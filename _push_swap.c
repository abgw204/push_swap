#include "stack.h"

static void give_indexes(t_stack *a)
{
    t_stack *current;
    int a_size;
    int index;

    a_size = ft_stacksize(a);
    index = 0;
    while (a_size > 0)
    {
        current = find_min(a);
        current->index = index++;
        a_size--;
    }
}

static void ft_sort(t_stack **a, t_stack **b)
{
    int a_size;

    a_size = ft_stacksize(*a);
    if (!check_sorted(*a))
    {
        if (a_size == 2)
            ft_sa(a);
        else if (a_size == 3)
            sort_three(a);
        else
            binary_radix(a, b);
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
        if (j == 0 && argv[i][0] != '0')
            ft_error();
        ft_stackadd_back(stack_a, ft_stacknew(j));
        i++;
    }
    if (!stack_a || check_duplicate(*stack_a))
    {
        ft_free(stack_a);
        ft_error();
    }
}
int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;

    if (argc == 1)
        return (0);
    if (argc == 2 && !argv[1][0])
        ft_error();
    else if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        init_stack_a(&a, argv);
    }
    else
        init_stack_a(&a, argv + 1);
    give_indexes(a);
    ft_sort(&a, &b);
    ft_free(&a);
}