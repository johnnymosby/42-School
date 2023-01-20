/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:41:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:41:42 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *to, const void *from, size_t size)
{
	int		i;
	char	*t;
	char	*f;

	if (to && from)
	{
		t = (char *)to;
		f = (char *)from;
		i = 0;
		while (size > 0)
		{
			t[i] = f[i];
			i++;
			size--;
		}
	}
	return (to);
}
