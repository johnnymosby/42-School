/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:00:54 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 18:12:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack_a(t_array *array, t_context *ct)
{
	ct->st_a = ft_calloc(1, sizeof(t_stack_a));
	if (ct->st_a == NULL)
		exit_with_message(ct, "malloc & stack_a");
	ct->st_a->arr = malloc(sizeof(int) * array->n);
	if (ct->st_a->arr == NULL)
		exit_with_message(ct, "malloc & stack_a->arr");
	ct->st_a->n = array->n;
	ct->st_a->d = 0;
}

void	create_stack_b(t_array *array, t_context *ct)
{
	ct->st_b = ft_calloc(1, sizeof(t_stack_b));
	if (ct->st_b == NULL)
		exit_with_message(ct, "malloc & stack_b");
	ct->st_b->arr = malloc(sizeof(int) * array->n);
	if (ct->st_b->arr == NULL)
		exit_with_message(ct, "malloc & stack_b->arr");
	ct->st_b->n = 0;
}

void	copy_input_to_stack_a(t_stack_a *stack_a, t_array *array)
{
	int	i;
	int	n;

	i = 0;
	n = array->n;
	while (n > 0)
	{
		stack_a->arr[n - 1] = array->nums[i];
		i++;
		n--;
	}
}
