/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:03:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/14 13:03:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int	ft_distinct(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_no_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

void	convert(int nbr, char *base, char *p)
{
	int	j;

	j = 0;
	if (nbr >= ft_strlen(base))
	{
		while (p[j] != '\0')
			j++;
		p[j] = base[nbr % ft_strlen(base)];
		p[j + 1] = '\0';
		convert(nbr / ft_strlen(base), base, p);
	}
	else
	{
		while (p[j] != '\0')
			j++;
		p[j] = base[nbr];
		p[j + 1] = '\0';
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	p[16];
	int		i;

	p[0] = '\0';
	if ((ft_strlen(base) > 1) && (ft_distinct(base) == 1)
		&& (ft_no_sign(base) == 1))
	{
		if (nbr < 0)
		{
			write(1, "-", 1);
			nbr *= -1;
		}
		convert(nbr, base, p);
	}
	i = 0;
	while (ft_strlen(p) - i != -1)
	{
		write(1, p + ft_strlen(p) - i - 1, 1);
		i++;
	}
}
