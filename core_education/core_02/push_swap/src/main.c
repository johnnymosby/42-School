/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/02/27 14:41:00 by rbasyrov         ###   ########.fr       */
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



int	main(int argc, char **argv)
{
	char	*input;
/* 	int		*array;
	t_stack	*stack_a;
	t_stack	*stack_b; */

	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	clean_input(input);
/* 	initialise_array(array, input);
	transform_input_to_array(array, input);
	initialise_stack(stack_a, input);
	initialise_stack(stack_b, input);
	transform_array_to_stack_a(input, stack_a); */
	ft_printf("%s\n", input);
}
