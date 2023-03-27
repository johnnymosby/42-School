/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:37:42 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 18:07:56 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_number_of_elements(char *input, t_context *ct)
{
	int	i;
	int	n;

	if (input[0] == '\0')
		clean_before_end(ct);
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

void	create_array(char *input, t_context *ct)
{
	ct->arr = ft_calloc(1, sizeof(t_array));
	if (ct->arr == NULL)
		exit_with_message(ct, "malloc & array");
	ct->arr->n = count_number_of_elements(input, ct);
	ct->arr->nums = malloc(sizeof(int) * ct->arr->n);
	if (ct->arr->nums == NULL)
		exit_with_message(ct, "malloc & array->nums");
	ct->arr->inds = malloc(sizeof(int) * ct->arr->n);
	if (ct->arr->inds == NULL)
		exit_with_message(ct, "malloc & array->inds");
}

static int	return_next_number(char *input, t_context *ct)
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
	if (number_in_text == NULL)
		exit_with_message(ct, "malloc & number_in_text");
	i = -1;
	while (++i < n_symbols)
		number_in_text[i] = input[i];
	number_in_text[i] = '\0';
	number = ft_atoi_improved(number_in_text, ct);
	free(number_in_text);
	return (number);
}

t_array	*transform_input_to_array(t_array *array, char *inp, t_context *ct)
{
	int		i;
	int		n_symbols;
	int		next_number;

	i = 0;
	n_symbols = 0;
	while (i != array->n)
	{
		next_number = return_next_number(inp + n_symbols, ct);
		array->nums[i] = next_number;
		array->inds[i] = i;
		while (inp[n_symbols] != '\0'
			&& inp[n_symbols] != ' ')
			n_symbols++;
		if (inp[n_symbols] == ' ')
			n_symbols++;
		i++;
	}
	return (array);
}

void	change_values_to_their_order(t_array *array)
{
	int	i;
	int	n;

	i = 0;
	n = array->n;
	while (i < n)
	{
		array->nums[i] = i + 1;
		i++;
	}
}
