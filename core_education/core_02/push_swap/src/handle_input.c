/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:04:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/02/27 14:06:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_space_after_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	s[i] = ' ';
	s[i + 1] = '\0';
}

char	*collapse_arguments(int argc, char **argv)
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
	s = malloc(sizeof(char) * (len + argc));
	if (s == NULL)
		exit (EXIT_FAILURE);
	i = 1;
	while (i != argc)
	{
		ft_strlcat(s, argv[i], len + argc);
		i++;
		if (i != argc)
			add_space_after_word(s);
	}
	return (s);
}

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