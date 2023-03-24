/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 20:36:23 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	order_chunks_in_a(t_context *ct)
{
	while (ct->st_a->arr[0] != ct->arr->n)
	{
		move_and_save("rra", ct);
	}
}

void	sort(t_stack_a *st_a, t_stack_b *st_b, t_context *ct)
{
	if (st_a->n < 4)
		sort_less_than_four_numbers(st_a, ct);
	else
	{
		move_from_a_to_b(st_a, ct);
		move_from_b_to_a(st_a, st_b, ct);
		order_chunks_in_a(ct);
	}
}
