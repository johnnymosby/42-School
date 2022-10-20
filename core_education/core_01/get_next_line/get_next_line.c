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

char	*get_next_line(int fd)
{
	char		*buf;
	char		*ret;
	int			k;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (0);
	ret = NULL;
	buf = malloc(BUFFER_SIZE + 1);
	k = read_line(fd, buf);
	while (k > 0)
	{
		if (!buf)
			return (0);
		if (ret == NULL)
			ret = ft_strdup(buf);
		else
			ret = ft_strjoin(ret, buf);
		if (ft_strchr(ret, '\n'))
			break ;
		k = read_line(fd, buf);
	}
	free(buf);
	if ((k == 0 && ret == 0) || k == -1)
		return (0);
	return (ret);
}
