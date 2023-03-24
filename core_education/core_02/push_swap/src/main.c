/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:27:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 20:03:35 by rbasyrov         ###   ########.fr       */
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
	sort(ct->st_a, ct->st_b, ct);
	print_commands(ct->cms);
	clean_before_end(ct);
}
