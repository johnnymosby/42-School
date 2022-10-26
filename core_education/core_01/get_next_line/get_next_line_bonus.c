/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/09 16:43:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_until_nl_or_o(int fd, char *save)
{
	int		nchar;
	char	*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	nchar = 1;
	while (nchar != 0 && ft_strchr(save, '\n') == 0)
	{
		nchar = read(fd, buf, BUFFER_SIZE);
		if (nchar == -1)
		{
			free(buf);
			free(save);
			return (0);
		}
		buf[nchar] = '\0';
		save = ft_strjoin(save, buf);
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
	right = ft_strdup(save + i + 1);
	free(save);
	return (right);
}

char	*get_next_line(int fd)
{
	static char	*save[2048];
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 2048)
		return (0);
	save[fd] = read_until_nl_or_o(fd, save[fd]);
	if (!save[fd])
		return (0);
	ret = crop_left(save[fd]);
	save[fd] = crop_right(save[fd]);
	return (ret);
}
