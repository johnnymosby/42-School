/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:57:51 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/17 20:57:52 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	counter;

	counter = 0;
	while (src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*tab;

	i = 0;
	tab = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (tab == (void *) 0)
		return ((void *) 0);
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = (char *)malloc(sizeof(char) * (tab[i].size + 1));
		if (tab[i].copy == (void *) 0)
			return ((void *) 0);
		j = 0;
		while (j < tab[i].size)
		{
			tab[i].copy[j] = av[i][j];
			j++;
		}
		tab[i].copy[j] = '\0';
		i++;
	}
	tab[i].str = 0;
	return (tab);
}