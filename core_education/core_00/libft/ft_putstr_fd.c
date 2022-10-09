/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:42:56 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:42:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	counter;

	if (!s)
		return ;
	counter = 0;
	while (*(s + counter) != '\0')
	{
		write(fd, (s + counter), 1);
		counter++;
	}
}
