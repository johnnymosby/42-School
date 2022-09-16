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

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	what_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (!(('a' <= base[i] && base[i] <= 'z') || ('A' <= base[i]
					&& base[i] <= 'Z') || ('0' <= base[i] && base[i] <= '9')))
			return (0);
		j = 1;
		while (base[i + j] != '\0')
		{
			if (base[i] == base[i + j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base_small(int nbr, char *base)
{
	int	p[32];
	int	i;
	int	b;

	b = what_base(base);
	ft_putchar('-');
	if ((2147483647 % b + 1) % b == 0)
	{
		p[0] = 0;
		nbr = 2147483647 / b + 1;
	}
	else
	{
		p[0] = 48 % b;
		nbr = 2147483647 / b;
	}
	i = 1;
	while (nbr > 0)
	{
		p[i] = nbr % b;
		nbr /= b;
		i++;
	}
	while (i > 0)
		ft_putchar(base[p[--i]]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	p[32];
	int	i;

	i = 0;
	if (what_base(base) != 0)
	{
		if (nbr == -2147483648)
			ft_putnbr_base_small(nbr, base);
		else if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr == 0)
			ft_putchar('0');
		while (nbr > 0)
		{
			p[i] = nbr % what_base(base);
			nbr /= what_base(base);
			i++;
		}
		while (i > 0)
			ft_putchar(base[p[--i]]);
	}
}
