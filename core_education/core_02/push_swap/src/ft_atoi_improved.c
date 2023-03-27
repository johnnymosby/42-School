/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_improved.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:07:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 18:05:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exit_within_atoi(char *str, t_context *ct)
{
	free(str);
	exit_with_message(ct, "not integer");
}

//exit if the number is not int
int	ft_atoi_improved(char *string, t_context *ct)
{
	int						i;
	int						n;
	unsigned long long int	number;

	i = 0;
	n = 1;
	number = 0;
	while (string[i] == ' ' || string[i] == '\f' || string[i] == '\n'
		|| string[i] == '\r' || string[i] == '\t' || string[i] == '\v')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			n *= -1;
		i++;
	}
	while ('0' <= string[i] && string[i] <= '9')
	{
		number = number * 10 + (string[i] - '0');
		if (number > 2147483647)
			exit_within_atoi(string, ct);
		i++;
	}
	return (n * number);
}
