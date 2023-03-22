/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:31:43 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 11:23:09 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(int *arr, int n)
{
	int	temp;
	int	i;

	i = n;
	if (i > 1)
	{
		temp = arr[i - 1];
		arr[i - 1] = arr[i - 2];
		arr[i - 2] = temp;
	}
}

void	ft_sa(t_stack_a *stack_a)
{
	ft_s(stack_a->arr, stack_a->n);
}

void	ft_sb(t_stack_b *stack_b)
{
	ft_s(stack_b->arr, stack_b->n);
}

void	ft_ss(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
}
