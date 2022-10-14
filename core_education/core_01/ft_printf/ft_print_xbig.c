/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xbig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:02:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/13 19:02:20 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_xbig(va_list ap)
{
	long long int		nbr;
	char				*base;
	int					p[64];
	int					i;
	int					j;

	i = 0;
	base = ft_strcreate("0123456789ABCDEF");
	nbr = (unsigned int)va_arg(ap, int);
	if (nbr == 0)
		free(base);
	if (nbr == 0)
		return (write(1, "0", 1));
	while (nbr > 0)
	{
		p[i] = nbr % 16;
		nbr /= 16;
		i++;
	}
	j = 8 * (i > 7) + i * (i <= 7);
	i = j;
	while (j > 0)
		ft_putchar(base[p[--j]]);
	free(base);
	return (i);
}
