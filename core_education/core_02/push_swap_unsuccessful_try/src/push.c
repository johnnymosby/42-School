/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:43:52 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 16:14:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_p(t_stack *stack_to, t_stack *stack_from)
{
	int	n_to;
	int	n_from;
	int	*st_to;
	int	*st_from;

	n_from = stack_from->n_elems;
	if (n_from != 0)
	{
		n_to = stack_to->n_elems;
		st_to = stack_to->array;
		st_from = stack_from->array;
		st_to[n_to] = st_from[n_from - 1];
		stack_to->n_elems += 1;
		stack_from->n_elems -= 1;
	}
}

void	ft_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_p(stack_a, stack_b);
}

void	ft_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_p(stack_b, stack_a);
}
