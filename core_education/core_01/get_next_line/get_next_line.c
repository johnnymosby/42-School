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

int	read_line(int fd, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < BUFFER_SIZE)
	{
		j = read(fd, buf + i, 1);
		if (j == -1)
			return (-1);
		if (!j)
			return (i);
		if (buf[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*ret;
	int			j;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (buf);
	i = read_line(fd, buf);
	if (i == 0)
	{
		free(buf);
		return (0);
	}
	if (i == -1)
		return (0);
	j = 0;
	ret = malloc(i + 1);
	if (!ret)
	{
		free(buf);
		return (0);
	}
/*	printf("=%i=\n", j);*/
	while (j < i)
	{
		ret[j] = buf[j];
		if (ret[j] == '\n')
		{
			j++;
			break ;
		}
		j++;
	}
	ret[j] = '\0';
	free(buf);
	return (ret);
}
/*
int	main(void)
{
	int		fd;
	char	*test;

	fd = open("41_no_nl", O_RDWR);
	test = get_next_line(fd);
	printf("%s?", test);
	free(test);
	test = get_next_line(fd);
	printf("%s?", test);
	free(test);	test = get_next_line(fd);
	printf("%s?", test);
	free(test);	test = get_next_line(fd);
	printf("%s?", test);
	free(test);	test = get_next_line(fd);
	printf("%s?", test);
	free(test);	test = get_next_line(fd);
	printf("%s?", test);
	free(test);	test = get_next_line(fd);
	printf("%s?", test);
	free(test);
	close(fd);
}
*/
