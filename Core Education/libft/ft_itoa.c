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

static	int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

static void	ft_rev_char_tab(char *str)
{
	char	temp;
	int		counter;
	int		len;

	counter = -1;
	len = ft_strlen(str);
	while (++counter < len / 2)
	{
		temp = *(str + counter);
		*(str + counter) = *(str + len - 1 - counter);
		*(str + len - 1 - counter) = temp;
	}
}

static int	ft_intlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		sign;

	sign = n < 0;
	str = ft_calloc(ft_intlen(n) + (sign) + 1, sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	i = 0;
	while (n != 0)
	{
		str[i] = '0' + ft_abs(n % 10);
		n /= 10;
		i++;
	}
	if (sign)
		str[i] = '-';
	ft_rev_char_tab(str);
	return (str);
}
