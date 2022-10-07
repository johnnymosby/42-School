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
	void	*t;
	size_t	z;

	z = count * size;
	if (count != 0 && z / count != size)
	{
		return (0);
	}
	t = malloc(count * size);
	if (!t)
		return (0);
	ft_bzero(t, count * size);
	return (t);
}
