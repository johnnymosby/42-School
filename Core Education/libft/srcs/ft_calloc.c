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

void	*ft_calloc(size_t count, size_t size)
{
	void			*t;
	unsigned char	*b;

	t = (void *)malloc(count * size);
	if (!t)
		return (NULL);
	b = t;
	while (size > 0)
	{
		*b = 0;
		b++;
		size--;
	}
	return (t);
}
