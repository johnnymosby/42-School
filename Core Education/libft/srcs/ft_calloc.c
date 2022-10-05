/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:41:10 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:41:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *calloc(size_t count, size_t size)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char*)malloc(count * size);
	while (i < size)
	{
		p[i] = 0;
		i++;
	}
	return (p);
}
