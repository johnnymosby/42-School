/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_with_bubble_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:43:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/21 16:36:40 by rbasyrov         ###   ########.fr       */
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

void	sort_with_bubble_sort_array(t_array *array)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < array->n - 1)
	{
		counter2 = counter1;
		while (counter2 < array->n)
		{
			if (array->nums[counter1] > array->nums[counter2])
			{
				ft_swap(array->nums + counter1, array->nums + counter2);
				ft_swap(array->inds + counter1, array->inds + counter2);
			}
			counter2++;
		}
		counter1++;
	}
}

void	sort_with_bubble_sort_indexes(t_array *array)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < array->n - 1)
	{
		counter2 = counter1;
		while (counter2 < array->n)
		{
			if (array->inds[counter1] > array->inds[counter2])
			{
				ft_swap(array->nums + counter1, array->nums + counter2);
				ft_swap(array->inds + counter1, array->inds + counter2);
			}
			counter2++;
		}
		counter1++;
	}
}
