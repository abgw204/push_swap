/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:28:48 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/02 00:28:50 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

int check_duplicate(t_stack *stack_a)
{
    t_stack *next;

    while (stack_a)
    {
        next = stack_a->next;
        while (next)
        {
             if (stack_a->nbr == next->nbr)
                return (1);
            next = next->next;
        }
        stack_a = stack_a->next;
    }
    return (0);
}