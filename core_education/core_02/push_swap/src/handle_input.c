/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:04:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/01/22 14:31:08 by rbasyrov         ###   ########.fr       */
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
