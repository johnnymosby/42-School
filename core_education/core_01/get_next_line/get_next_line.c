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

static char	*ft_strcpy(char *dest, char *src)
{
	int counter;

	counter = 0;
	while (src[counter])
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (dest);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	n;

	n = 0;
	size -= 1;
	while (src[n] && n < size)
	{
		dest[n] = src[n];
		n++;
	}
	dest[n] = '\0';
	return (n);
}

void	ft_bzero(void *block, size_t size)
{
	unsigned char	*b;

	b = block;
	while (size > 0)
	{
		*b = 0;
		b++;
		size--;
	}
}

char *init_temp(int size, char *buf)
{
	char *r;

	r = malloc(size + 1);
	if (!r)
		return (0);
	r[size + 1] = '\0';
	while (size >= 0)
	{
		r[size] = buf[size];
		size--;
	}
	return (r);
}

void	*ft_memmove(void *to, const void *from, int size)
{
	int		i;
	char		*t;
	char		*f;

	if (!to || !from)
		return (0);
	t = (char *)to;
	f = (char *)from;
	i = 0;
	if (to < from)
	{
		while (i < size)
		{
			t[i] = f[i];
			i++;
		}
	}
	else
	{
		while (size-- > 0)
			t[size] = f[size];
	}
	return (to);
}

int	read_line(int fd, char *save, char *ret)
{
	char *buf;
	int	 n_chars;
	char *newline;
	char *temp;

	n_chars = 1;
	while (n_chars && newline)
	{
		buf = malloc(BUFFER_SIZE + 1);
		if (!buf)
			return (0);
		if (save[0])
		{
			buf = ft_strcpy(buf, save);
			ft_bzero(save, BUFFER_SIZE + 1);
		}
		else
		{
			ft_bzero(buf, BUFFER_SIZE + 1);
			n_chars = read(fd, buf, BUFFER_SIZE);
		}
		newline = ft_strchr(buf, '\n');
		if (newline)
		{
			save = ft_strcpy(save, newline + 1);
			temp = init_temp(newline - buf, buf);
			/* handle error with malloc*/
			ret = ft_strjoin(ret, temp);
			free(temp);
		}
		else
			ret = ft_strjoin(ret, buf);
	}
	free(buf);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*ret;
	int 		n;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (0);
	ret = 0;
	n = read_line(fd, save, ret);
	if (!n)
		return (0);
	return (ret);
}

int main(void)
{
	int fd = open("multiple_line_no_nl", O_RDWR);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
}