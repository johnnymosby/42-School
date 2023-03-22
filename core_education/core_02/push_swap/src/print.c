/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:01:51 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 13:13:53 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_array(t_array *array)
{
	int	i;

	i = 0;
	ft_printf("arr->nums: ");
	while (i != array->n)
	{
		ft_printf("%i ", array->nums[i]);
		i++;
	}
	ft_printf("\narr->inds: ");
	i = 0;
	while (i != array->n)
	{
		ft_printf("%i ", array->inds[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_a(t_stack_a *stack)
{
	int	i;

	i = 0;
	ft_printf("stack_a->arr: ");
	while (i != stack->n)
	{
		ft_printf("%i ", stack->arr[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack_b(t_stack_b *stack)
{
	int	i;

	i = 0;
	ft_printf("stack_b->arr: ");
	while (i != stack->n)
	{
		ft_printf("%i ", stack->arr[i]);
		i++;
	}
	ft_printf("\n");
}
