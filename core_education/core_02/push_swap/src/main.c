/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/02 19:19:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_malloc_error(char *s)
{
	free(s);
	ft_printf("Wrong input");
	exit(EXIT_FAILURE);
}

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

void	clean_input(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (i == 0)
			while (input[i] == ' ')
				i++;
		while (input[i] == '0' && input[i + 1] != ' ')
			i++;
 		while (input[i] == ' ' && input[i + 1] == ' ')
			i++;
		input[j] = input[i];
		i++;
		j++;
	}
	input[j] = '\0';
}


int	count_number_of_elements(char *input)
{
	int i;
	int n;

	exit_if_null(input[0] == '\0', input);
	i = 0;
	n = 1;
	while (input[i] != '\0')
	{
		if (input[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

void	exit_if_null(int if_exit, char *input)
{
	if (if_exit == 1)
	{
		free(input);
		exit(EXIT_FAILURE);
	}	
}

int	return_next_number(char *input)
{
	int		n_symbols;
	int		i;
	char	*number_in_text;
	int		number;

	n_symbols = 0;
	i = 0;
	while (!(input[i] == '\0' || (i > 0 && input[i - 1] == ' ')))
	{
		if (input[i] != ' ')
			n_symbols++;
		i++;
	}
	number_in_text = malloc(sizeof(int) * (n_symbols + 1));
	exit_if_null(number_in_text == NULL, input);
	i = 0;
	while (i != n_symbols)
	{
		number_in_text[i] = input[i];
		i++;
	}
	number_in_text[i] = '\0';
	number = ft_atoi(number_in_text);
	free(number_in_text);
	return (number);
}

t_array *create_array(char *input)
{
	t_array	*array;

	array = malloc(sizeof(t_array));
	exit_if_null(array == NULL, input);
	array->n_elems = count_number_of_elements(input);
	array->array = malloc(sizeof(int) * array->n_elems);
	exit_if_null(array->array == NULL, input);
	array->indexes = malloc(sizeof(int) * array->n_elems);
	exit_if_null(array->indexes == NULL, input);
	return (array);
}

void transform_input_to_array(t_array *array, char *input)
{
	int	i;
	int	n_symbols;
	int	next_number;

	i = 0;
	n_symbols = 0;
	while (i != array->n_elems)
	{
		next_number = return_next_number(input + n_symbols);
		if (next_number != (int)next_number)
		{
			free(array);
			free(input);
			exit(EXIT_FAILURE);
		}
		array->array[i] = (int)next_number;
		array->indexes[i] = i;
		while (input[n_symbols] != '\0'
			&& input[n_symbols] != ' ')
			n_symbols++;
		if (input[n_symbols] == ' ')
			n_symbols++;
		i++;
	}
}

void print_array(t_array *array)
{
	int i;

	i = 0;
	while (i != array->n_elems)
	{
		ft_printf("%i!\n", array->array[i]);
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*input;
 	t_array	*array;
/*	t_stack	*stack_a;
	t_stack	*stack_b; */

	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	clean_input(input);
	array = create_array(input);
	transform_input_to_array(array, input);
/* 	initialise_stack(stack_a, input);
	initialise_stack(stack_b, input);
	transform_array_to_stack_a(input, stack_a); */
	print_array(array);
	ft_printf("%s\n", input);
}
