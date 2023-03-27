/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort__numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:15 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 20:07:23 by rbasyrov         ###   ########.fr       */
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

static int	find_the_smallest(t_stack_a *st_a)
{
	int	n;
	int	i;
	int	j;

	n = st_a->n + 1;
	i = 0;
	j = st_a->n - 1;
	while (i != st_a->n)
	{
		if (st_a->arr[i] < n)
		{
			n = st_a->arr[i];
			j = st_a->n - i - 1;
		}
		i++;
	}
	return (j);
}

void	sort_less_than_six_numbers(t_stack_a *st_a,
									t_stack_b *st_b,
									t_context *ct)
{
	int	ind_sm;

	while (st_a->n > 3)
	{
		ind_sm = find_the_smallest(st_a);
		while (ind_sm != 0 && ind_sm != st_a->n)
		{
			if (ind_sm <= (st_a->n / 2))
			{
				move_and_save("ra", ct);
				ind_sm--;
			}
			else
			{
				move_and_save("rra", ct);
				ind_sm++;
			}
		}
		move_and_save("pb", ct);
	}
	sort_less_than_four_numbers(st_a, ct);
	if (st_b->n == 2 && st_b->arr[0] > st_b->arr[1])
		move_and_save("sb", ct);
	while (st_b->n != 0)
		move_and_save("pa", ct);
}
