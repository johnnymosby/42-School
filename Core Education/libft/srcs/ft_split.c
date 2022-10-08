/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:43:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:43:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_find(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_stringlen(const char *str, char *charset)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0' && ft_find(*(str + n), charset) != 1)
	{
		n++;
	}
	return (n);
}

static void	ft_strcpy(char *dest, const char *src, char *charset)
{
	int	counter;

	counter = 0;
	while (*(src + counter) != '\0'
		&& ft_find(*(src + counter), charset) != 1)
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
}

static int	to_array(int count, const char *str, char *charset, char **ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0' && (ft_find(str[j], charset) == 1))
		j++;
	while (i < count)
	{
		ret[i] = malloc(sizeof(char) * (ft_stringlen(str + j, charset) + 1));
		if (ret[i] == 0)
			return (0);
		ft_strcpy(ret[i], str + j, charset);
		i++;
		j = j + ft_stringlen(str + j, charset);
		while (ft_find(*(str + j), charset) == 1)
			j++;
	}
	ret[i] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	int		i;
	int		j;
	char	**ret;
	char	cc[2];

	if (!s)
		return (0);
	cc[0] = c;
	cc[1] = '\0';
	count = 0;
	i = -1;
	while (s[++i])
	{
		if ((ft_find(s[i], cc) == 0 && ft_find(s[i + 1], cc) == 1)
			|| (ft_find(s[i], cc) == 0 && s[i + 1] == '\0'))
			count++;
	}
	ret = malloc(sizeof(char *) * (count + 1));
	if (ret == 0)
		return (0);
	j = to_array(count, s, cc, ret);
	if (j == 0)
		return (0);
	return (ret);
}
