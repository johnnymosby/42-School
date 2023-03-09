/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_up.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 16:04:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_up(t_stack *stack)
{
	int	*st;
	int	temp;
	int	n;

	st = stack->array;
	n = stack->n_elems;
	temp = st[n - 1];
	while (n > 0)
	{
		st[n - 1] = st[n - 2];
		n--;
	}
	st[0] = temp;
}

void	ft_ra(t_stack *stack_a)
{
	ft_r_up(stack_a);
}

void	ft_rb(t_stack *stack_b)
{
	ft_r_up(stack_b);
}

void	ft_rr(t_stack *stack_a, t_stack *stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
}
