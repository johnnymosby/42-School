/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 19:37:44 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_until_nl_or_o(int fd, char *save)
{
	int		nchar;
	char	*buf;

	buf = malloc(100 + 1);
	if (!buf)
		return (0);
	nchar = 1;
	while (nchar != 0 && ft_strchr_upd(save, '\n') == 0)
	{
		nchar = read(fd, buf, 100);
		if (nchar == -1)
		{
			free(buf);
			free(save);
			return (0);
		}
		buf[nchar] = '\0';
		save = ft_strjoin_upd(save, buf);
	}
	free(buf);
	return (save);
}

char	*crop_left(char *save)
{
	int		i;
	char	*left;

	i = 0;
	if (!save[0])
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	left = malloc(i + 1 + (save[i] == '\n'));
	if (!left)
		return (0);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		left[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		left[i] = save[i];
		i++;
	}
	left[i] = '\0';
	return (left);
}

char	*crop_right(char *save)
{
	int		i;
	char	*right;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	right = ft_strdup_upd(save + i + 1);
	free(save);
	return (right);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	if (fd < 0 || 100 < 1)
		return (0);
	save = read_until_nl_or_o(fd, save);
	if (!save)
		return (0);
	ret = crop_left(save);
	save = crop_right(save);
	return (ret);
}
