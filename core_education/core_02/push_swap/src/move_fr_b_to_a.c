/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_fr_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 20:19:10 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 17:15:42 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_n_from_bot_b(int n, t_stack_b *st_b)
{
	int	i;

	i = 0;
	while (i != st_b->n && st_b->arr[i] != n)
		i++;
	return (i + 1);
}

static int	find_n_from_top_b(int n, t_stack_b *st_b)
{
	int	i;
	int	j;

	i = st_b->n - 1;
	j = 0;
	while (j != ((st_b->n) - 1) && st_b->arr[i - j] != n)
		j++;
	return (j);
}

static void	move_from_top(int n, t_stack_a *st_a, t_stack_b *st_b,
			t_context *ct)
{
	while (st_b->arr[(st_b->n - 1)] != n)
	{
		if (st_a->d > 0 && st_b->arr[(st_b->n - 1)] < st_a->arr[0])
			move_and_save("rb", ct);
		else
		{
			move_and_save("pa", ct);
			move_and_save("ra", ct);
			st_a->d += 1;
		}
	}
}

static void	move_from_bottom(int n, t_stack_a *st_a, t_stack_b *st_b,
			t_context *ct)
{
	while (st_b->arr[(st_b->n - 1)] != n)
	{
		if (st_a->d > 0 && st_b->arr[(st_b->n - 1)] < st_a->arr[0])
			move_and_save("rrb", ct);
		else
		{
			move_and_save("pa", ct);
			move_and_save("ra", ct);
			st_a->d += 1;
		}
	}
}

void	move_from_b_to_a(t_stack_a *st_a, t_stack_b *st_b, t_context *ct)
{
	int	n;

	n = ct->st_b->n;
	while (st_b->n != 0 && n > 0)
	{
		if (st_b->arr[(st_b->n - 1)] == n)
		{
			move_and_save("pa", ct);
			n--;
		}
		else if (st_a->d > 0 && st_a->arr[0] == n)
		{
			move_and_save("rra", ct);
			n--;
			st_a->d -= 1;
		}
		else if (find_n_from_top_b(n, st_b) < find_n_from_bot_b(n, st_b))
			move_from_top(n, st_a, st_b, ct);
		else
			move_from_bottom(n, st_a, st_b, ct);
	}
}
// void	move_from_b_to_a(t_stack_a *st_a, t_stack_b *st_b, t_context *ct)
// {
// 	int	n;

// 	n = ct->arr->n;
// 	while (st_b->n != 0 && n > 0)
// 	{
// 		if (st_b->arr[(st_b->n - 1)] == n)
// 		{
// 			move_and_save("pa", ct);
// 			n--;
// 		}
// 		else if (st_a->d > 0 && st_a->arr[0] == n)
// 		{
// 			move_and_save("rra", ct);
// 			n--;
// 			st_a->d -= 1;
// 		}
// 		else if (find_n_from_top_b(n, st_b) < find_n_from_bot_b(n, st_b))
// 		{
// 			while (st_b->arr[(st_b->n - 1)] != n)
// 			{
// 				if (st_a->d > 0 && st_b->arr[(st_b->n - 1)] < st_a->arr[0])
// 				{
// 					move_and_save("rb", ct);
// 				}
// 				else
// 				{
// 					move_and_save("pa", ct);
// 					move_and_save("ra", ct);
// 					st_a->d += 1;
// 				}
// 			}
// 		}
// 		else
// 		{
// 			while (st_b->arr[(st_b->n - 1)] != n)
// 			{
// 				if (st_a->d > 0 && st_b->arr[(st_b->n - 1)] < st_a->arr[0])
// 				{
// 					move_and_save("rrb", ct);
// 				}
// 				else
// 				{
// 					move_and_save("pa", ct);
// 					move_and_save("ra", ct);
// 					st_a->d += 1;
// 				}
// 			}
// 		}
// 	}
// }
