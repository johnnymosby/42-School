/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 13:36:24 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//the function returns the the smallest integer divisible by two, 
		//so that n ** 2 > n_of_elems in a stack
static int	even_rounded_sqrt(int nb)
{
	int	i;

	i = 0;
	while (i * i < nb && i <= 46340)
		i++;
	if (i % 2 == 0)
		return (i);
	else if (i < 46340 && i % 2 == 1)
		return (i + 1);
	else
		return (0); 
}

// static void	order_chunks_in_b(int ch_s, t_context *ct)
// {
// 	while (ct->st_b->arr[0] >= (ch_s))
// 	{
// 		move_and_save("rrb", ct);
// 		ft_printf("rrb\n");
// 	}
// }

// static void	inner_loop_from_a_to_b(int ch_s, int i, int j, t_context *ct)
// {
// 	while (ct->st_a->n != 0)
// 	{
// 		if (ct->st_a->arr[(ct->st_a->n) - 1] >= (i + ch_s)
// 			&& ct->st_a->arr[(ct->st_a->n) - 1] < (i + 2 * ch_s))
// 		{
// 			move_and_save("pb", ct);
// 			ft_printf("pb\n");
// 			move_and_save("rb", ct);
// 			ft_printf("rb\n");
// 			j++;
// 		}
// 		else if (ct->st_a->arr[(ct->st_a->n) - 1] >= (i)
// 			&& ct->st_a->arr[(ct->st_a->n) - 1] < (i + ch_s))
// 		{
// 			move_and_save("pb", ct);
// 			ft_printf("pb\n");
// 			j++;
// 		}
// 		else
// 		{
// 			move_and_save("ra", ct);
// 			ft_printf("ra\n");
// 		}
// 		if (j == 2 * ch_s)
// 		{
// 			i += j;
// 			j = 0;
// 			order_chunks_in_b(ch_s, ct);
// 		}
// 	}
// }

static void	order_chunks_in_b(int ch_s, t_context *ct)
{
	while (ct->st_b->arr[0] >= (ch_s))
	{
		move_and_save("rrb", ct);
	}
}

static void	inner_loop_from_a_to_b(int ch_s, int i, int j, t_context *ct)
{
	while (ct->st_a->n != 0)
	{
		if (ct->st_a->arr[(ct->st_a->n) - 1] >= (i + ch_s)
			&& ct->st_a->arr[(ct->st_a->n) - 1] < (i + 2 * ch_s))
		{
			move_and_save("pb", ct);
			move_and_save("rb", ct);
			j++;
		}
		else if (ct->st_a->arr[(ct->st_a->n) - 1] >= (i)
			&& ct->st_a->arr[(ct->st_a->n) - 1] < (i + ch_s))
		{
			move_and_save("pb", ct);
			j++;
		}
		else
		{
			move_and_save("ra", ct);
		}
		if (j == 2 * ch_s)
		{
			i += j;
			j = 0;
			order_chunks_in_b(ch_s, ct);
		}
	}
}

//before the main function, check if there 3 or 5 elements, if yes, apply the
		// the corresponding algorithms
//split into n chunks, where n is the smallest natural number divisible by two,
		//so that n ** 2 > n_of_elems in a stack
	//for every two chunks from the lowest (ct->st_a->n)ues, put an element from the 
		//first smallest chunk to the bot and the one from the second smallest
		//to the top -> when finished with all the elems, move to the next two
// always check how many elements are left in stack_a
	// if 3, then change their order with a special function for 3 elems
//ch_s for chink size
static void	move_from_st_a_to_st_b(t_stack_a *st_a, t_context *ct)
{
	int	ch_s;
	int	i;
	int	j;

	i = 1;
	j = 0;
	ch_s = even_rounded_sqrt(st_a->n);
	inner_loop_from_a_to_b(ch_s, i, j, ct);
}

// void	move_from_st_b_to_st_a(st_a, st_b, cms, ct)
// {
	
// }

void	sort(t_stack_a *st_a, t_context *ct)
{
	if (st_a->n < 4)
		sort_less_than_four_numbers(st_a, ct);
	else
	{
		move_from_st_a_to_st_b(st_a, ct);
		//move_from_st_b_to_st_a(st_a, st_b, cms, ct);
	}
}
