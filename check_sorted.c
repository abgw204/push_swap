/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:28:52 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/02 00:28:53 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool check_sorted(t_stack *stack_a)
{
    if (!stack_a)
        return (true);
    while (stack_a->next)
    {
        if (stack_a->nbr > stack_a->next->nbr)
            return (false);
        stack_a = stack_a->next;
    }
    return (true);
}