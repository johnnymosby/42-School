/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:46:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/16 12:46:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter) != '\0')
	{
		write(1, (str + counter), 1);
		counter++;
	}
}

void	ft_swap(char **a, char **b)
{
	char	*point;

	point = *a;
	*a = *b;
	*b = point;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] == '\0' && s2[i] == '\0')
		return (0);
	return (s1[i] - s2[i]);
}

void	ft_sort_int_tab(char **tab, int size)
{
	int	counter1;
	int	counter2;

	counter1 = 0;
	while (counter1 < size - 1)
	{
		counter2 = counter1;
		while (counter2 < size)
		{
			if (ft_strcmp(tab[counter1], tab[counter2]) > 0)
			{
				ft_swap(tab + counter1, tab + counter2);
			}
			counter2++;
		}
		counter1++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	if (argc != 1)
		ft_sort_int_tab(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
}
