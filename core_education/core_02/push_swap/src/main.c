/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:27:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/21 16:26:49 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_context	*ct;

	ct = init_context();
	ct->inp = parse_input(argc, argv, ct);
	ct->arr = init_array(ct->inp, ct);
	ft_printf("clean input: %s\n", ct->inp);
	print_array(ct->arr);
	clean_before_end(ct);
}
