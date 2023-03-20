/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:03:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/14 13:03:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(va_list ap)
{
	unsigned long int		nbr;
	char					*base;
	int						p[32];
	int						i;
	int						j;

	i = 0;
	base = ft_strcreate("0123456789abcdef");
	nbr = va_arg(ap, unsigned long int);
	if (nbr == 0)
	{
		free(base);
		return (write(1, "(nil)", 5));
	}
	while (nbr > 0)
	{
		p[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	j = i + write(1, "0x", 2);
	while (i > 0)
		ft_putchar(base[p[--i]]);
	free(base);
	return (j);
}
