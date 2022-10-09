/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 19:57:58 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/17 19:58:03 by rbasyrov         ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
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

char	*ft_strdup(char *src)
{
	char	*ret;

	ret = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (ret == (void *) 0)
		return ((void *) 0);
	return (ft_strcpy(ret, src));
}
