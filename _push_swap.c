/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:28:32 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/02 00:28:34 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
        current = find_min_and_next(a);
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
            ft_swap(a, 'a');
        else if (a_size == 3)
            sort_three(a);
        else if (a_size == 5)
            sort_five(a, b);
        else
            binary_radix(a, b);
    }
}

static void init_stack_a(t_stack **a, char *argv[], int quoted)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (argv[i])
    {
        j = atoi2(argv[i], a);
        ft_stackadd_back(a, ft_stacknew(j));
        i++;
    }
    if (quoted)
        ft_free_split(argv);
    if (!a || check_duplicate(*a))
        if_error_free_and_exit(a);
}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        return (0);
    if (argc == 2)
    {
        argv = ft_split(argv[1], ' ');
        init_stack_a(&a, argv, 1);
    }
    else
        init_stack_a(&a, argv + 1, 0);
    give_indexes(a);
    ft_sort(&a, &b);
    ft_free(&a);
    ft_free(&b);
}