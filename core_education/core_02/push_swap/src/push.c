/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:43:52 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 10:42:38 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_stack_a *stack_to, t_stack_b *stack_from)
{
	int	n_to;
	int	n_from;
	int	*st_to;
	int	*st_from;

	n_from = stack_from->n;
	if (n_from != 0)
	{
		n_to = stack_to->n;
		st_to = stack_to->arr;
		st_from = stack_from->arr;
		st_to[n_to] = st_from[n_from - 1];
		stack_to->n += 1;
		stack_from->n -= 1;
	}
}

void	ft_pb(t_stack_a *stack_from, t_stack_b *stack_to)
{
	int	n_to;
	int	n_from;
	int	*st_to;
	int	*st_from;

	n_from = stack_from->n;
	if (n_from != 0)
	{
		n_to = stack_to->n;
		st_to = stack_to->arr;
		st_from = stack_from->arr;
		st_to[n_to] = st_from[n_from - 1];
		stack_to->n += 1;
		stack_from->n -= 1;
	}
}
