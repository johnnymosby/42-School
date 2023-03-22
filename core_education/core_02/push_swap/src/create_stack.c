/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:00:54 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 13:58:50 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_a	*create_stack_a(t_array *array, t_context *ct)
{
	t_stack_a	*stack_a;

	stack_a = ft_calloc(1, sizeof(t_stack_a));
	if (stack_a == NULL)
		exit_with_message(ct, "malloc & stack_a");
	stack_a->arr = malloc(sizeof(int) * array->n);
	if (stack_a->arr == NULL)
		exit_with_message(ct, "malloc & stack_a->arr");
	stack_a->n = array->n;
	stack_a->d = 0;
	return (stack_a);
}

t_stack_b	*create_stack_b(t_array *array, t_context *ct)
{
	t_stack_b	*stack_b;

	stack_b = ft_calloc(1, sizeof(t_stack_b));
	if (stack_b == NULL)
		exit_with_message(ct, "malloc & stack_b");
	stack_b->arr = malloc(sizeof(int) * array->n);
	if (stack_b->arr == NULL)
		exit_with_message(ct, "malloc & stack_b->arr");
	stack_b->n = array->n;
	return (stack_b);
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
