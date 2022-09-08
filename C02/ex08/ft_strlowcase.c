/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:56:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 16:55:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter))
	{
		if (*(str + counter) >= 'A' && *(str + counter) <= 'Z')
			*(str + counter) = *(str + counter) + 32;
		counter++;
	}
	return (str);
}
