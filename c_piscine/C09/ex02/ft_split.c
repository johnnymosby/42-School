/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:39:42 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/22 13:39:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_find(char c, char *charset)
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

int	ft_strlen(char *str, char *charset)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0' && ft_find(*(str + n), charset) != 1)
	{
		n++;
	}
	return (n);
}

void	ft_strcpy(char *dest, char *src, char *charset)
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

int	to_array(int count, char *str, char *charset, char **ret)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] != '\0' && (ft_find(str[j], charset) == 1))
		j++;
	while (i < count)
	{
		ret[i] = malloc(sizeof(char) * (ft_strlen(str + j, charset) + 1));
		if (ret[i] == 0)
			return (0);
		ft_strcpy(ret[i], str + j, charset);
		i++;
		j = j + ft_strlen(str + j, charset);
		while (ft_find(*(str + j), charset) == 1)
			j++;
	}
	ret[i] = 0;
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		count;
	int		i;
	int		j;
	char	**ret;

	count = 0;
	i = 0;
	while (str[i])
	{
		if ((ft_find(str[i], charset) == 0 && ft_find(str[i + 1], charset) == 1)
			|| (ft_find(str[i], charset) == 0 && str[i + 1] == '\0'))
			count++;
		i++;
	}
	ret = malloc(sizeof(char *) * (count + 1));
	if (ret == 0)
		return (0);
	j = to_array(count, str, charset, ret);
	if (j == 0)
		return (0);
	return (ret);
}
