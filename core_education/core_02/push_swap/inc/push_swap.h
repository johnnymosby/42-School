/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:46:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 13:57:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "stdlib.h"
# include "unistd.h"
# define SIZE_COMMANDS_LIST 128
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

typedef struct s_commands
{
	int	*ts;
	int	n;
	int	max;
}	t_commands;

// inp stands for input
// arr for array
typedef struct s_context
{
	char		*inp;
	t_array		*arr;
	t_stack_a	*st_a;
	t_stack_b	*st_b;
	t_commands	*cms;
}	t_context;

t_context	*init_context(void);
void		exit_with_message(t_context *ct, char *message);

void		free_input(t_context *ct);
void		free_array(t_context *ct);
void		free_stack_a(t_context *ct);
void		free_stack_b(t_context *ct);
void		free_commands(t_context *ct);

char		*parse_input(int argc, char **argv, t_context *ct);
char		*collapse_arguments(int argc, char **argv, t_context *ct);
void		clean_input(char *input);
void		exit_if_not_numbers(char *s, t_context *ct);

t_array		*init_array(char *inp, t_context *ct);
t_array		*create_array(char *input, t_context *ct);
t_array		*transform_input_to_array(t_array *array, char *inp, t_context *ct);
int			ft_atoi_improved(const char *string, t_context *ct);
void		check_for_duplicates(t_array *arr, t_context *ct);
void		sort_with_bubble_sort_array(t_array *array);
void		sort_with_bubble_sort_indexes(t_array *array);
void		change_values_to_their_order(t_array *array);

t_commands	*create_commands(t_context *ct);
void		increase_cms(t_commands *cms, t_context *ct);
void		add_command(t_commands *cms, char *command, t_context *ct);
int			change_command_to_number(char *command);
char		*change_number_to_command(int num);
void		print_commands(t_commands *cms);

void		ft_sa(t_stack_a *stack_a);
void		ft_sb(t_stack_b *stack_b);
void		ft_ss(t_stack_a *stack_a, t_stack_b *stack_b);
void		ft_pa(t_stack_a *stack_a, t_stack_b *stack_b);
void		ft_pb(t_stack_a *stack_a, t_stack_b *stack_b);
void		ft_ra(t_stack_a *stack_a);
void		ft_rb(t_stack_b *stack_b);
void		ft_rr(t_stack_a *stack_a, t_stack_b *stack_b);
void		ft_rra(t_stack_a *stack_a);
void		ft_rrb(t_stack_b *stack_b);
void		ft_rrr(t_stack_a *stack_a, t_stack_b *stack_b);

t_stack_a	*init_stack_a(t_array *arr, t_context *ct);
t_stack_a	*create_stack_a(t_array *array, t_context *ct);
t_stack_b	*create_stack_b(t_array *array, t_context *ct);
void		copy_input_to_stack_a(t_stack_a *stack_a, t_array *array);

void		sort(t_stack_a *st_a, t_stack_b *st_b, t_commands *cms, t_context *ct);

void	clean_before_end(t_context *ct);

// to delete:
void		print_array(t_array *array);
void		print_stack_a(t_stack_a *stack);
void		print_stack_b(t_stack_b *stack);
#endif