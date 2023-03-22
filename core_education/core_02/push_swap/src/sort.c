/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:54:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 16:36:27 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//before the main function, check if there 3 or 5 elements, if yes, apply the
		// the corresponding algorithms
//split into n chunks, where n is the smallest natural number divisible by two,
		//so that n ** 2 > n_of_elems in
	//for every two chunks from the lowest values, put an element from the 
		//first smallest chunk to the bot and the one from the second smallest
		//to the top -> when finished with all the elems, move to the next two
// always check how many elements are left in stack_a
	// if 3, then change their order with a special function for 3 elems
void	move_from_st_a_to_st_b(st_a, st_b, cms, ct)
{

}

// void	move_from_st_b_to_st_a(st_a, st_b, cms, ct)
// {
	
// }

void	sort(t_stack_a *st_a, t_stack_b *st_b, t_commands *cms, t_context *ct)
{
	if (st_a->n < 4)
		sort_less_than_four_numbers(st_a, cms, ct);
	else
	{
		move_from_st_a_to_st_b(st_a, st_b, cms, ct);
		//move_from_st_b_to_st_a(st_a, st_b, cms, ct);
	}

}
