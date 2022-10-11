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

static int	ft_putnbr(int nb)
{
	static int i;


	i = 0;
	if (nb == -2147483648)
		return(ft_putstr("-2147483648"));
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb != -2147483648)
	{
		if (nb >= 10)
		{
			i += ft_putnbr(nb / 10);
			i += ft_putnbr(nb % 10);
		}
		else
			i += ft_putchar(nb + '0');
	}
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int 	c;

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
			if (fmt[i] == 'c')
				c += ft_putchar(va_arg(ap, int));
			else if (fmt[i] == 's')
				c += ft_putstr(va_arg(ap, char *));
			else if (fmt[i] == 'i')
				c += ft_putnbr(va_arg(ap, int));
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
	ft_printf("%c", '2');
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
