/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 20:39:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/01/22 14:35:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_not_numbers(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!((s[i] >= '0' && s[i] <= '9')
				|| s[i] == ' '
				|| s[i] == '-'))
		{
			free(s);
			ft_printf("Wrong input");
			exit(EXIT_FAILURE);
		}
		if (s[i] == '-'
			&& (!(s[i + 1] >= '0' && s[i + 1] <= '9')
				|| !(i == 0 || s[i - 1] == ' ')))
		{
			free(s);
			ft_printf("Wrong input [improperly placed '-']");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	char	*input;

	if (argc < 2)
		return (1);
	input = collapse_arguments(argc, argv);
	exit_if_not_numbers(input);
	ft_printf("%s", input);
}
