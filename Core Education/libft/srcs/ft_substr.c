/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:44:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:44:15 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*p;
	size_t		l;
	size_t		i;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
	{
		p = malloc(1);
		*p = 0;
		return (p);
	}
	p = malloc(1 + (l - start < len) * (l - start) + (l - start >= len) * len);
	if (!p || !s)
		return (0);
	i = 0;
	while (s[start] && i < len)
	{
		p[i] = (char)s[start];
		i++;
		start++;
	}
	p[i] = '\0';
	return (p);
}
