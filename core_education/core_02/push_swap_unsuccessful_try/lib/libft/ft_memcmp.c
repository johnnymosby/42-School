/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:41:30 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:41:32 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *a1, const void *a2, size_t size)
{
	unsigned char	*aone;
	unsigned char	*atwo;
	size_t			i;

	aone = (unsigned char *) a1;
	atwo = (unsigned char *) a2;
	i = 0;
	while (i < size)
	{
		if (aone[i] != atwo[i])
			return (aone[i] - atwo[i]);
		i++;
	}
	return (0);
}
