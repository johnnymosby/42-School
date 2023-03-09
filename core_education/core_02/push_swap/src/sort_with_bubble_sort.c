/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_bubble_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:43:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/05 17:10:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

void	sort_with_bubble_sort(t_array *array)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < array->n_elems - 1)
	{
		counter2 = counter1;
		while (counter2 < array->n_elems)
		{
			if (array->array[counter1] > array->array[counter2])
			{
				ft_swap(array->array + counter1, array->array + counter2);
				ft_swap(array->indexes + counter1, array->indexes + counter2);
			}
			counter2++;
		}
		counter1++;
	}
}
