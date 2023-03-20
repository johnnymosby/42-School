/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:33:52 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/09 12:08:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_if_malloc_error(char *s)
{
	free(s);
	ft_printf("Wrong input");
	exit(EXIT_FAILURE);
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

void	exit_if_null(int if_exit, ...)
{
	va_list	ap;
	void	*to_free;

	if (if_exit == 1)
	{
		va_start(ap, if_exit);
		while (1)
		{
			to_free = va_arg(ap, void *);
			if (to_free == NULL)
				break ;
			free(to_free);
		}
		va_end(ap);
		exit(EXIT_FAILURE);
	}	
}
