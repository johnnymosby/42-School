/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:22:51 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/16 10:32:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*create_stack(t_array *array)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_array));
	stack->array = malloc(sizeof(int) * array->n_elems);
	stack->n_elems = 0;
	stack->n_to_leave = 0;
	return (stack);
}

t_stack	*create_stack_a(t_array *array)
{
	t_stack	*stack_a;

	stack_a = create_stack(array);
	if (stack_a == NULL || stack_a->array == NULL)
		exit_if_null(1, array->array, array->indexes, array,
			stack_a->array, stack_a);
	return (stack_a);
}

t_stack	*create_stack_b(t_array *array, t_stack *stack_a)
{
	t_stack	*stack_b;

	stack_b = create_stack(array);
	if (stack_b == NULL || stack_b->array == NULL)
		exit_if_null(1, array->array, array->indexes, array,
			stack_a->array, stack_a,
			stack_b->array, stack_b);
	return (stack_b);
}
