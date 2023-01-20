/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/01/05 12:06:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*collapse_input(int argc, char **argv)
{
	int		len;
	int		i;
	char	*s;

	len = 0;
	i = 1;
	while (i != argc)
	{
		len += ft_strlen(argv[i]);
		i++;
	}
	s = malloc(sizeof(char) * (len + 1));
	if (s == NULL)
		exit (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	char	*s;

	if (argc < 2)
		return (1);
	s = collapse_input(argc, argv);
}
