/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:46:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/21 16:41:35 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "stdlib.h"
# include "unistd.h"

// nums for numbers
// inds for indexes
// n for the number of elements
typedef struct s_array
{
	int	*nums;
	int	*inds;
	int	n;
}	t_array;

// arr for array
// n for the number of elements
// d for the number of elements in the bottom waiting for their turn
typedef struct s_stack_a
{
	int	*arr;
	int	n;
	int	d;
}	t_stack_a;

typedef struct s_stack_b
{
	int	*arr;
	int	n;
}	t_stack_b;

// inp stands for input
// arr for array
typedef struct s_context
{
	char		*inp;
	t_array		*arr;
	t_stack_a	*st_a;
	t_stack_b	*st_b;
}	t_context;

t_context	*init_context(void);
void		exit_with_message(t_context *ct, char *message);

void		free_input(t_context *ct);
void		free_context(t_context *ct);
void		free_array(t_context *ct);
void		free_stack_a(t_context *ct);
void		free_stack_b(t_context *ct);

char		*parse_input(int argc, char **argv, t_context *ct);
char		*collapse_arguments(int argc, char **argv, t_context *ct);
void		clean_input(char *input);
void		exit_if_not_numbers(char *s, t_context *ct);

t_array		*init_array(char *inp, t_context *ct);
t_array		*create_array(char *input, t_context *ct);
t_array		*transform_input_to_array(t_array *array, char *inp, t_context *ct);
int			ft_atoi_improved(const char *string, t_context *ct);
void		sort_with_bubble_sort_array(t_array *array);
void		sort_with_bubble_sort_indexes(t_array *array);
void		change_values_to_their_order(t_array *array);




void	clean_before_end(t_context *ct);

// to delete:
void	print_array(t_array *array);
void	print_stack_a(t_stack_a *stack);
void	print_stack_b(t_stack_b *stack);
#endif