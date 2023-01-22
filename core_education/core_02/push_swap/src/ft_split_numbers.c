/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:43:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/01/22 15:12:34 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(char *s)
{
	int n;
	int i;

	n = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if ((s[i] >= '0' && s[i] <= '9')
			&& !(s[i + 1] >= '0' && s[i + 1] <= '9'))
			n++;
		i++;
	}
	return (n);
}

int	*split_input_to_array(char *input)
{
	int n_numbers;
	int	*array;

	n_numbers = count_numbers(input);
	if (n_numbers == 0)
	{
		free(input);
		ft_printf("Wrong input [no numbers]");
		exit(EXIT_FAILURE);
	}
	array = malloc(sizeof(int) * n_numbers)
}
