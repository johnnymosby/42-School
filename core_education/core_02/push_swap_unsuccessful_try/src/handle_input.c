/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:04:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/05 17:12:50 by rbasyrov         ###   ########.fr       */
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

int	return_next_number(char *input)
{
	int		n_symbols;
	int		i;
	char	*number_in_text;
	int		number;

	n_symbols = 0;
	i = 0;
	while (!(input[i] == '\0' || (i > 0 && input[i - 1] == ' ')))
	{
		if (input[i] != ' ')
			n_symbols++;
		i++;
	}
	number_in_text = malloc(sizeof(int) * (n_symbols + 1));
	exit_if_null(number_in_text == NULL, input);
	i = 0;
	while (i != n_symbols)
	{
		number_in_text[i] = input[i];
		i++;
	}
	number_in_text[i] = '\0';
	number = ft_atoi(number_in_text);
	free(number_in_text);
	return (number);
}
