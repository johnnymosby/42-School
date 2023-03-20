/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:37:42 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 12:51:06 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_number_of_elements(char *input)
{
	int	i;
	int	n;

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

t_array	*create_array(char *input)
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

void	transform_input_to_array(t_array *array, char *input)
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

void	print_array(t_array *array)
{
	int	i;

	i = 0;
	ft_printf("array->array: ");
	while (i != array->n_elems)
	{
		ft_printf("%i ", array->array[i]);
		i++;
	}
	ft_printf("\narray->indexes: ");
	i = 0;
	while (i != array->n_elems)
	{
		ft_printf("%i ", array->indexes[i]);
		i++;
	}
	ft_printf("\n");
}

void	print_stack(t_stack *stack)
{
	int	i;

	i = 0;
	ft_printf("stack->array: ");
	while (i != stack->n_elems)
	{
		ft_printf("%i ", stack->array[i]);
		i++;
	}
	ft_printf("\n");
}
