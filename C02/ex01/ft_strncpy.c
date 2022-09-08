/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 16:59:40 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/06 16:59:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	counter;

	counter = 0;
	while (src[counter] && (counter < n))
	{
		dest[counter] = src[counter];
		counter++;
	}
	while (dest[counter] && counter < n)
	{
		dest[counter] = '\0';
		counter++;
	}
	return (dest);
}