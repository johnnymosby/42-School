/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:27:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 18:09:44 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	*ct;

	ct = init_context();
	ct->inp = parse_input(argc, argv, ct);
	init_array(ct->inp, ct);
	init_stack_a(ct->arr, ct);
	create_stack_b(ct->arr, ct);
	create_commands(ct);
	sort(ct->st_a, ct->st_b, ct);
	print_commands(ct->cms);
	clean_before_end(ct);
}
