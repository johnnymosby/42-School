/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:35:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/13 18:35:28 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_i(va_list ap)
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
	while (--i > -1)
		ft_putchar(snb[i + 1]);
	return (j);
}
