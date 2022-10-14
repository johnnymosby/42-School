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
#include <limits.h>

int	ft_distributor(va_list ap, char val)
{
	if (val == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (val == 's')
		return (ft_printf_s(ap));
	else if (val == 'i' || val == 'd')
		return (ft_printf_i(ap));
	else if (val == 'u')
		return (ft_printf_u(ap));
	else if (val == '%')
		return (ft_putchar('%'));
	else if (val == 'p')
		return (ft_printf_p(ap));
	else if (val == 'x')
		return (ft_printf_x(ap));
	else if (val == 'X')
		return (ft_printf_xbig(ap));
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
