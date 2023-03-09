/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:46:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 12:46:51 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "stdlib.h"
# include "unistd.h"

/* typedef struct s_stack_elem
{
	t_stack_elem	*next;
	t_stack_elem	*previous;
}	t_stack_elem;

typedef struct s_stack
{
	t_stack_elem	*top;
}	t_stack;

t_stack	*transform_input_to_array(char *input, t_stack stack);
void	initialise_stack(t_stack *stack, char *input); */

typedef struct s_array
{
	int	*array;
	int	*indexes;
	int	n_elems;
}	t_array;
typedef struct s_stack
{
	int	*array;
	int	n_elems;
}	t_stack;

void	transform_input_to_array(t_array *array, char *input);

void	exit_if_malloc_error(char *s);
void	exit_if_null(int if_exit, ...);
int		return_next_number(char *input);
int		count_number_of_elements(char *input);
t_array	*create_array(char *input);

void	add_space_after_word(char *s);
void	clean_input(char *input);
char	*collapse_arguments(int argc, char **argv);

void	exit_if_not_numbers(char *s);
void	sort_with_bubble_sort(t_array *array);

void	print_array(t_array *array);
void	print_stack(t_stack *stack);

t_stack	*create_stack(t_array *array);

#endif