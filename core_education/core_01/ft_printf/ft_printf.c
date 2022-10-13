/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:31:09 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/11 15:31:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"
static int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

static int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str + i, 1);
		i++;
	}
	return (i);
}

static int	ft_puti(va_list ap)
{
	int		i;
	int		j;
	int		nb;
	char	snb[16];

	if (ap == NULL)
		return (write(1, "(nil)", 5));
	nb = va_arg(ap, int);
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	i = 1;
	j = nb < 0;
	if (nb < 0)
		nb *= write(1, "-", 1) * -1;
	while (nb > 9)
	{
		snb[i] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	snb[i] = '0' + nb;
	j += i;
	i++;
	while (--i > 0)
		ft_putchar(snb[i]);
	return (j);
}

static int	ft_putu(va_list ap)
{
	int				i;
	int				j;
	unsigned int	nb;
	char			*snb;

	nb = va_arg(ap, unsigned int);
	snb = malloc(10);
	i = 0;
	while (nb > 9)
	{
		snb[i] = '0' + nb % 10;
		nb /= 10;
		i++;
	}
	snb[i] = '0' + nb;
	j = i;
	while (i > -1)
	{
		ft_putchar(snb[i]);
		i--;
	}
	free(snb);
	return (j + 1);
}

int	ft_distributor(va_list ap, char val)
{
	char	*s;

	if (val == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (val == 's')
	{
		s = va_arg(ap, char *);
		if (!s)
			return (write(1, "(null)", 6));
		return (ft_putstr(s));
	}
	else if (val == 'i' || val == 'd')
		return (ft_puti(ap));
	else if (val == 'u')
		return (ft_putu(ap));
	else if (val == '%')
		return (ft_putchar('%'));
	else
		return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		c;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	c = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			c += ft_distributor(ap, fmt[i]);
		}
		else
			c += ft_putchar(fmt[i]);
		i++;
	}
	va_end(ap);
	return (c);
}

/*int main(void)
{
	ft_printf("%i\n", 2147483647);
}*/

/*
int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	char	cv;
	int		i;

	if (!fmt)
		return (0);
	va_start(ap, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == 'c')
		{
			cv = va_arg(ap, int);
			ft_putchar(cv);
		}
		fmt++;
		i++;
	}
	va_end(ap);
	return (i);
}
*/

/*
static int	ft_putu(unsigned int nb)
{
	int				i;
	unsigned int	temp;

	i = 0;
	while (nb > 9)
	{
		temp = nb;
		while (temp > 9)
			temp /= 10;
		i += ft_putchar(temp + '0');
		nb %= 10;
	}
	i += ft_putchar(nb + '0');
	return (i);
}*/
