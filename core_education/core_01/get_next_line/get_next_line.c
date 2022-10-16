/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/09 16:43:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

int	nchar_read(int fd, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j)
	{
		j = read(fd, buf + i, 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	start;
	static int	nchar;
	char		*ret;
	int			j;
	int 		i;

	if (nchar == 0)
	{
		buf = malloc(BUFFER_SIZE);
		if (!buf)
		{
			free(buf);
			return (0);
		}
		nchar = nchar_read(fd, buf);
	}
	if (nchar < 1)
	{
		free(buf);
		return (0);
	}
	j = 0;
	while ((start + j) <= nchar && (start + j) <= BUFFER_SIZE)
	{
		if (buf[start + j] == '\n')
		{
			j++;
			break ;
		}
		j++;
	}
	if (!j)
	{
		free(buf);
		return (0);
	}
	ret = malloc(j + 1);
	if (!ret)
	{
		free(buf);
		return (0);
	}
	ret[j] = '\0';
	i = j;
	while (--j >= 0)
		ret[j] = buf[start + j];
	start = start + i;
/*	if (start == BUFFER_SIZE - 1)
		free(buf);*/
	return (ret);
}

int	main(void)
{
	int		fd;

	fd = open("test", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	close(fd);
}
