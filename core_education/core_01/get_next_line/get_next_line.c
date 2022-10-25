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
	left = malloc(i + 2);
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
	if (!save[0])
	{
		free(save);
		return (0);
	}
	while (save[i])
	{
		if (save[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	if (save[i] == 0)
	{
		free(save);
		return (0);
	}
	right = malloc(ft_stringlen(save) - i + 2);
	if (!right)
	{
		free (save);
		return (0);
	}
	right = ft_strdup(save + i);
	free(save);
	return (right);
}

/*char	*crop_right(char *save)
{
	int		i;
	int		j;
	char	*right;

	i = 0;
	if (!save[0])
	{
		free(save);
		return (0);
	}
	while (save[i] && save[i] != '\n')
		i++;
	right = malloc(ft_stringlen(save) - i + 1);
	if (!right)
	{
		free (save);
		return (0);
	}
	j = 0;
	i++;
	while (save[i])
		right[j++] = save[i++];
	right[j] = '\0';
	free (save);
	return (right);
}*/

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	if (!save)
	{
		save = malloc(1);
		if (!save)
			return (0);
		save[0] = '\0';
	}
	save = read_until_nl_or_o(fd, save);
	if (!save)
		return (0);
	if (!ft_strchr(save, '\n'))
	{
		ret = crop_left(save);
		free(save);
		return (ret);
	}
	ret = crop_left(save);
	save = crop_right(save);
	return (ret);
}
/*int main(void)
{
	int	fd = open("nl", O_RDWR);
	char *str;
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	str = get_next_line(fd);
	printf("%s", str);
	free(str);
	close(fd);
}*/
