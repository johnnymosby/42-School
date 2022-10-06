/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:41:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:41:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
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

static char	*ft_charcat(char *dest, char src)
{
	unsigned int	i;

	i = 0;
	while (dest[i])
		i++;
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

static int	ft_pow(int nb, int power)
{
	int	value;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	value = nb;
	while (--power > 0)
		nb *= value;
	return (nb);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		nn;
	int		sign;

	if (n == -2147483648)
	{
		str = malloc(12);
		if (!str)
			return (0);
		str = ft_strcpy(str, "-2147483648");
		return (str);
	}
	sign = 0;
	if (n < 0)
	{
		n *= -1;
		sign = 1;
	}
	i = 0;
	nn = n;
	while (nn / 10 != 0)
	{
		nn /= 10;
		i++;
	}
	str = malloc(i + sign + 1);
	if (!str)
		return (0);
	if (sign == 1)
		str = ft_strcpy(str, "-");
	while (i != -1)
	{
		str = ft_charcat(str, (n / ft_pow(10, i)) + '0');
		n %= ft_pow(10, i);
		i--;
	}
	return (str);
}
