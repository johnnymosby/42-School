/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_longest_subsequence.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 13:57:21 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/17 14:02:09 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_long_seq	*create_seq_struct(t_array *array)
{
	t_long_seq	*arr;

	arr = malloc(sizeof(t_long_seq));
	arr->refs = ft_calloc(array->n_elems, sizeof(int));
	arr->top_vals = ft_calloc(array->n_elems, sizeof(int));
	return (arr);
}

// static t_long_seq	*create_seq_struct(t_array *array,
// 	t_stack *stack_a, t_stack *stack_b)
// {
// 	t_long_seq	*arr;

// 	arr = malloc(sizeof(t_long_seq));
// 	arr->refs = ft_calloc(array->n_elems, sizeof(int));
// 	arr->top_vals = ft_calloc(array->n_elems, sizeof(int));
// 	exit_if_null(arr == NULL || arr->refs == NULL || arr->top_vals,
// 		array->array, array->indexes, array,
// 		stack_a->array, stack_a,
// 		stack_b->array, stack_b,
// 		arr->top_vals, arr->refs, arr);
// 	return (arr);
// }

// 'seq' is a structure to calculate the longest sequence in the input

static int	find_the_index_of_the_first_elem(t_stack *stack_a)
{
	int	i;

	i = 0;
	while (stack_a->array[i] != 1)
		i++;
	return (i);
}

static int	choose_the_pile(t_long_seq *seq, t_stack *stack_a, int elem)
{
	int	i;

	i = 0;
	while (i != stack_a->n_elems || seq->top_vals[i] != 0
		|| seq->top_vals[i] < elem)
	{
		i++;
	}
	if (i == stack_a->n_elems)
	{
		return (-1);
	}
	else
	{
		seq->top_vals[i] = elem;
		seq->last_pile = i;
		return (i);
	}
}

static void	perform_patience_sort(t_stack *stack_a, t_long_seq *seq, int start)
{
	int	n;
	int	p;
	int	what_pile;
	int	elem;

	n = 0;
	p = 0;
	seq->refs[stack_a->array[start]] = -1;
	seq->top_vals[p] = stack_a->array[start];
	seq->last_pile = 0;
	while (n != stack_a->n_elems)
	{
		elem = stack_a->array[(start + n) % stack_a->n_elems];
		what_pile = choose_the_pile(seq, stack_a, elem);
		if (what_pile == 0)
			seq->refs[elem] = -1;
		else
			seq->refs[elem] = seq->top_vals[what_pile - 1];
		n++;
	}
}

int	find_the_longest_subsequence(t_array *array,
	t_stack *stack_a)
{
	t_long_seq	*seq;
	int			start;

	seq = create_seq_struct(array);
	// seq = create_seq_struct(array, stack_a, stack_b);
	start = find_the_index_of_the_first_elem(stack_a);
	perform_patience_sort(stack_a, seq, start);
	return (seq->last_pile);
}
