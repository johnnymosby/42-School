/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:41:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:41:04 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
