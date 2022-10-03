/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:04:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 16:55:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	int	counter;

	counter = 0;
	while (*(str + counter))
	{
		if (*(str + counter) >= 'a' && *(str + counter) <= 'z')
			*(str + counter) = *(str + counter) - 32;
		counter++;
	}
	return (str);
}
