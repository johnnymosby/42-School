/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 16:19:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/17 14:02:44 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	shift_to_stack_b(t_array *array, t_stack *stack_a, t_stack *stack_b)
// {
// 	int	second_last;
// 	int	last;
// 	int	n;

// 	n = stack_a->n_elems;
// 	while (n != 0)
// 	{
		
// 	}
// }

// void	find_what_to_leave_in_a(t_stack *stack_a, t_stack *stack_b,
// 	t_array *array)
// {
// 	int	*to_leave;
// 	int	*st_a;
// 	int	i;
// 	int	j;
// 	int	n;
// 	int	last_value;

// 	to_leave = malloc(sizeof(int) * stack_a->n_elems);
// 	exit_if_null(to_leave == 0, array->array, array->indexes, array,
// 		stack_a->array, stack_a,
// 		stack_b->array, stack_b);
// 	i = 0;
// 	n = 1;
// 	st_a = stack_a->array;
// 	while (i != stack_a->n_elems - 1)
// 	{
// 		last_value = st_a[i];
// 		j = i + 1;
// 		while (j % stack_a->n_elems != i)
// 		{
// 			if (last_value < st_a[j])
// 			{
// 				to_leave[j] = 1;
// 				last_value = st_a[j];
// 				n++;
// 			}
// 			else
// 			{
// 				to_leave[j] = 0;
// 			}
// 			j++;			
// 		}
// 		if (n > stack_a->n_to_leave)
// 	}
// }

// the_longest_subsequence_with_patience_sort(int *array, int n_elems)
// {
	
// }

void	push_swap(t_array *array, t_stack *stack_a)
{
	// shift_to_stack_b(array, stack_a, stack_b);
	// sfind_what_to_leave_in_a(stack_a, stack_b, array);
	ft_printf("the length - 1 of the longest sub: %i\n", find_the_longest_subsequence(array, stack_a));
}
