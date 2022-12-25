/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:44:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:44:06 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find(const char c, char const *charset)
{
	size_t	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*p;
	size_t		i;
	size_t		len;

	i = 0;
	len = 0;
	if (!s1 || !set)
		return (0);
	while (ft_find(s1[i], set) == 1)
		i++;
	while (s1[i + len])
		len++;
	while (ft_find(s1[i + len - 1], set) == 1 && len != 0)
		len--;
	p = malloc(len + 1);
	if (!p)
		return (0);
	p[len] = '\0';
	while (len-- != 0)
	{
		p[len] = (char)s1[i + len];
	}
	return (p);
}
