/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:19 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 19:30:38 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_stringlen_upd(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strdup_upd(char *src)
{
	char	*ret;
	int		i;

	ret = malloc(ft_stringlen_upd(src) + 1);
	if (!ret)
		return (0);
	i = 0;
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_strjoin_upd(char *s1, char *s2)
{
	char	*p;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (0);
		s1[0] = '\0';
	}
	p = malloc(ft_stringlen_upd(s1) + ft_stringlen_upd(s2) + 1);
	if (!p)
		free(s1);
	if (!p)
		return (0);
	i = -1;
	j = -1;
	while (s1[++i])
		p[i] = s1[i];
	free(s1);
	while (s2[++j])
		p[i + j] = s2[j];
	p[i + j] = '\0';
	return (p);
}

char	*ft_strchr_upd(const char *string, int c)
{
	int	i;

	i = 0;
	if (!string)
		return (0);
	if (!c)
	{
		while (string[i])
			i++;
		return ((char *)string + i);
	}
	while (string[i])
	{
		if ((const char) c == string[i])
			return ((char *)string + i);
		i++;
	}
	return (0);
}
