/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:27:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/23 14:46:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	*ct;

	ct = init_context();
	ct->inp = parse_input(argc, argv, ct);
	ct->arr = init_array(ct->inp, ct);
	ct->st_a = init_stack_a(ct->arr, ct);
	ct->st_b = create_stack_b(ct->arr, ct);
	ct->cms = create_commands(ct);
	// ft_printf("clean input: %s\n", ct->inp);// to delete
	// print_array(ct->arr); // to delete
	// ft_printf("st_a n: %i\n", ct->st_a->n);
	// print_stack_a(ct->st_a);
	// ft_printf("st_b n: %i\n", ct->st_b->n);
	// print_stack_b(ct->st_b);
	sort(ct->st_a, ct);
	// ft_printf("after sorting:\n");
	// ft_printf("st_a n: %i\n", ct->st_a->n);
	// print_stack_a(ct->st_a);
	// ft_printf("st_b n: %i\n", ct->st_b->n);
	// print_stack_b(ct->st_b);
	print_commands(ct->cms);
	clean_before_end(ct);
}
