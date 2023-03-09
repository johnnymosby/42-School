/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 13:23:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* void initialise_stack(t_stack	*stack, char *input)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		exit_if_malloc_error(input);
	stack->top->previous = NULL;
	stack->top->next = NULL;
}


t_stack	*transform_input_to_array(char *input, t_stack *stack)
{
	int	i;

	i = 0;
	while (input[i] != '\0')
	
	
}
 */

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

void	copy_input_to_stack_a(t_stack *stack_a, t_array *array)
{
	int	i;
	int	n;

	i = 0;
	n = array->n_elems;
	stack_a->n_elems = n;
	while (n > 0)
	{
		stack_a->array[i] = array->array[i];
		i++;
		n--;
	}
}

int	main(int argc, char **argv)
{
	char	*input;
	t_array	*array;
	t_stack	*stack_a;
	//t_stack	*stack_b;
	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	clean_input(input);
	array = create_array(input);
	transform_input_to_array(array, input);
	free(input);
	stack_a = create_stack(array);
	copy_input_to_stack_a(stack_a, array);
	//stack_b = create_stack(array);

	sort_with_bubble_sort(array);
/* 	initialise_stack(stack_a, input);
	initialise_stack(stack_b, input);
	transform_array_to_stack_a(input, stack_a); */
	ft_printf("after sorting:\n");
	print_array(array);
	print_stack(stack_a);
	ft_printf("\n");
}
