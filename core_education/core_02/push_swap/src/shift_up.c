/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 16:52:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_up(int *arr, int n)
{
	int	temp;
	int	i;

	i = n;
	temp = arr[i - 1];
	while (i > 1)
	{
		arr[i - 1] = arr[i - 2];
		i--;
	}
	arr[0] = temp;
}

void	ft_ra(t_stack_a *stack_a)
{
	ft_r_up(stack_a->arr, stack_a->n);
}

void	ft_rb(t_stack_b *stack_b)
{
	ft_r_up(stack_b->arr, stack_b->n);
}

void	ft_rr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
