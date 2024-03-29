/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:05:51 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 16:29:34 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_space_after_word(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	s[i] = ' ';
	s[i + 1] = '\0';
}

static void	skip_zeroes(char *input)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] == '0' && (input[i + 1] != ' ' && input[i + 1] != '\0'))
		i++;
	input[j] = input[i];
	i++;
	j++;
	while (input[0] != '\0' && input[i] != '\0')
	{
		if (input[i - 1] == ' ' && input[i] == '0')
			while (input[i] == '0'
				&& (input[i + 1] != ' ' && input[i + 1] != '\0'))
				i++;
		input[j] = input[i];
		i++;
		j++;
	}
	if (input[0] != '\0')
		input[j] = '\0';
}

char	*collapse_arguments(int argc, char **argv, t_context *ct)
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
		exit_with_message(ct, "malloc & parsing");
	i = 1;
	s[0] = '\0';
	while (i != argc)
	{
		ft_strlcat(s, argv[i], len + argc);
		i++;
		if (i != argc)
			add_space_after_word(s);
	}
	return (s);
}

void	clean_input(char *input)
{
	int	i;
	int	j;

	skip_zeroes(input);
	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (i == 0)
			while (input[i] == ' ')
				i++;
		while (input[i] == ' ' && input[i + 1] == ' ')
			i++;
		input[j] = input[i];
		i++;
		j++;
	}
	input[j] = '\0';
}

void	check_for_duplicates(t_array *arr, t_context *ct)
{
	int	i;

	i = 1;
	while (i != arr->n)
	{
		if (arr->nums[i] == arr->nums[i - 1])
			exit_with_message(ct, "duplicates");
		i++;
	}
}
