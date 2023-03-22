/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:38:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 10:45:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// the next two functions are identical
void	ft_rra(t_stack_a *stack_a)
{
	int	*st;
	int	temp;
	int	n;
	int	i;

	st = stack_a->arr;
	temp = st[0];
	n = stack_a->n;
	i = 0;
	while (i < n - 1)
	{
		st[i] = st[i + 1];
		i++;
	}
	st[n - 1] = temp;
}

void	ft_rrb(t_stack_b *stack_b)
{
	int	*st;
	int	temp;
	int	n;
	int	i;

	st = stack_b->arr;
	temp = st[0];
	n = stack_b->n;
	i = 0;
	while (i < n - 1)
	{
		st[i] = st[i + 1];
		i++;
	}
	st[n - 1] = temp;
}

void	ft_rrr(t_stack_a *stack_a, t_stack_b *stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
}
