/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:43:18 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:43:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_stringlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
		n++;
	return (n);
}

static char	*ft_stringcpy(char *dest, char *src)
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

	ret = malloc(sizeof(char) * (ft_stringlen(src) + 1));
	if (ret == (void *) 0)
		return ((void *) 0);
	return (ft_stringcpy(ret, src));
}
