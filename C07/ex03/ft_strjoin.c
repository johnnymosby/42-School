/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:22:59 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/17 20:23:01 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

void	ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
	{
		i++;
	}
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ret;
	int		i;
	int		length;

	i = -1;
	length = (size - 1) * ft_strlen(sep);
	while (++i < size)
		length += ft_strlen(strs[i]);
	ret = malloc(sizeof(char) * (length + 1));
	if (ret == (void *) 0)
		return ((void *) 0);
	i = -1;
	while (++i < size)
	{
		ft_strcat(ret, strs[i]);
		if (i + 1 < size)
			ft_strcat(ret, sep);
	}
	return (ret);
}
