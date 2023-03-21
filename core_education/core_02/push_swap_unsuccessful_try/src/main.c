/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/21 16:48:46 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(t_array *array)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_array));
	exit_if_null(stack == NULL, array->array, array->indexes, array);
	stack->array = malloc(sizeof(int) * array->n_elems);
	exit_if_null(stack->array == NULL, array->array, array->indexes,
		array);
	stack->n_elems = 0;
	return (stack);
}

// the order of a stack in the array is reversed: the top is in the end
void	copy_input_to_stack_a(t_stack *stack_a, t_array *array)
{
	int	i;
	int	n;

	i = 0;
	n = array->n_elems;
	stack_a->n_elems = n;
	while (n > 0)
	{
		stack_a->array[n - 1] = array->array[i];
		i++;
		n--;
	}
}

void	change_values_to_their_order(t_array *array)
{
	int	i;
	int	n;

	i = 0;
	n = array->n_elems;
	while (i < n)
	{
		array->array[i] = i + 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*input;
	t_array	*array;
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	clean_input(input);
	array = create_array(input);
	transform_input_to_array(array, input);
	free(input);
	sort_with_bubble_sort_array(array);
	change_values_to_their_order(array);
	sort_with_bubble_sort_indexes(array);
	stack_a = create_stack_a(array);
	copy_input_to_stack_a(stack_a, array);
	stack_b = create_stack_b(array, stack_a);
	print_stack(stack_a);
	print_stack(stack_b);
	push_swap(array, stack_a, stack_b);
	sort_with_bubble_sort_array(array);
	ft_printf("\nafter sorting:\n");
	print_array(array);
	print_stack(stack_a);
	print_stack(stack_b);
	ft_printf("\n");.
}
