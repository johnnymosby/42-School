/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:57:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 12:40:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_context	*init_context(void)
{
	t_context	*ct;

	ct = ft_calloc(1, sizeof(t_context));
	if (ct == NULL)
		exit_with_message(ct, "malloc & ct");
	return (ct);
}

char	*parse_input(int argc, char **argv, t_context *ct)
{
	char	*input;

	input = collapse_arguments(argc, argv, ct);
	exit_if_not_numbers(input, ct);
	clean_input(input);
	return (input);
}

t_array	*init_array(char *inp, t_context *ct)
{
	t_array	*array;

	array = create_array(inp, ct);
	transform_input_to_array(array, inp, ct);
	sort_with_bubble_sort_array(array);
	check_for_duplicates(array, ct);
	change_values_to_their_order(array);
	sort_with_bubble_sort_indexes(array);
	return (array);
}

t_stack_a *init_stack_a(t_array *arr, t_context *ct)
{
	t_stack_a	*st_a;

	st_a = create_stack_a(arr, ct);
	copy_input_to_stack_a(st_a, arr);
	return (st_a);
}
