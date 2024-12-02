/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gada-sil <gada-sil@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:29:44 by gada-sil          #+#    #+#             */
/*   Updated: 2024/12/02 00:29:44 by gada-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdio.h>
void	sort_three(t_stack **a)
{
	t_stack	*max;

	max = find_max(*a);
	if (!max->prev)
	{
		ft_ra(a);
		if (check_sorted(*a) == true)
			return ;
		ft_swap(a, 'a');
	}
	else if (max->prev != NULL && max->next != NULL)
	{
		ft_rra(a);
		if (check_sorted(*a) == true)
			return ;
		ft_swap(a, 'a');
	}
	else
	{
		if (check_sorted(*a) == true)
			return ;
		ft_swap(a, 'a');
	}
}