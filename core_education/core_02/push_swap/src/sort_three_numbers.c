/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:15 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/23 11:45:18 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// {0 1 2} : already sorted
// {0 2 1} : sa ra
// {1 0 2} : sa
// {1 2 0} : rra
// {2 0 1} : ra
// {2 1 0} : sa rra
void	sort_three_numbers(t_stack_a *st_a, t_context *ct)
{
	if (st_a->arr[2] < st_a->arr[0] && st_a->arr[0] < st_a->arr[1])
	{
		move_and_save("sa", ct);
		move_and_save("ra", ct);
	}
	else if (st_a->arr[1] < st_a->arr[2] && st_a->arr[2] < st_a->arr[0])
		move_and_save("sa", ct);
	else if (st_a->arr[0] < st_a->arr[2] && st_a->arr[2] < st_a->arr[1])
		move_and_save("rra", ct);
	else if (st_a->arr[1] < st_a->arr[0] && st_a->arr[0] < st_a->arr[2])
		move_and_save("ra", ct);
	else if (st_a->arr[0] < st_a->arr[1] && st_a->arr[1] < st_a->arr[2])
	{
		move_and_save("sa", ct);
		move_and_save("rra", ct);
	}
}


void	sort_less_than_four_numbers(t_stack_a *st_a, t_context *ct)
{
	if (st_a->n == 2 && st_a->arr[0] < st_a->arr[1])
		move_and_save("sa", ct);
	else if (st_a->n == 3)
		sort_three_numbers(st_a, ct);
}
	