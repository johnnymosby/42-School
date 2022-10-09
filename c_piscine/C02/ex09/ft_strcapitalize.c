/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:56:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 17:28:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_char_is_alpha_or_num(char str)
{
	if (str > 64 && str < 91)
		return (0);
	if (str > 96 && str < 123)
		return (0);
	if (str > 47 && str < 58)
		return (0);
	return (1);
}

char	*ft_strcapitalize(char *str)
{
	int	counter;

	counter = 1;
	if (*str >= 'a' && *str <= 'z')
		*str = *str - 32;
	while (*(str + counter))
	{
		if (ft_char_is_alpha_or_num(*(str + counter - 1)) == 1)
		{
			if (*(str + counter) >= 'a' && *(str + counter) <= 'z')
				*(str + counter) = *(str + counter) - 32;
		}
		else
		{
			if (*(str + counter) >= 'A' && *(str + counter) <= 'Z')
				*(str + counter) = *(str + counter) + 32;
		}
		counter++;
	}
	return (str);
}
