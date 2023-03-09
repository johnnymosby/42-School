/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:31:43 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 16:04:29 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_s(t_stack *stack)
{
	int	temp;
	int	*st;
	int	n;

	st = stack->array;
	n = stack->n_elems;
	if (n > 1)
	{
		temp = st[n - 1];
		st[n - 1] = st[n - 2];
		st[n - 2] = temp;
	}
}

void	ft_sa(t_stack *stack_a)
{
	ft_s(stack_a);
}

void	ft_sb(t_stack *stack_b)
{
	ft_s(stack_b);
}

void	ft_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_s(stack_a);
	ft_s(stack_b);
}
