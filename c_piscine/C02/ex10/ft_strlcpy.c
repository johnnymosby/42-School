/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:29:25 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 17:51:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
