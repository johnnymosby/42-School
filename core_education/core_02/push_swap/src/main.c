/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/01/22 14:42:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	char	*input;

	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	ft_printf("%s", input);
}
