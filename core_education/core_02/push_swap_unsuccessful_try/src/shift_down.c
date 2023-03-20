/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 16:04:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_r_down(t_stack *stack)
{
	int	*st;
	int	temp;
	int	n;
	int	i;

	st = stack->array;
	temp = st[0];
	n = stack->n_elems;
	i = 0;
	while (i < n - 1)
	{
		st[i] = st[i + 1];
		i++;
	}
	st[n - 1] = temp;
}

void	ft_rra(t_stack *stack_a)
{
	ft_r_down(stack_a);
}

void	ft_rrb(t_stack *stack_b)
{
	ft_r_down(stack_b);
}

void	ft_rrr(t_stack *stack_a, t_stack *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
