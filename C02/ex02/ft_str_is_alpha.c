/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 12:51:41 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 13:36:13 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str);

int	ft_str_is_alpha(char *str)
{
	int		counter;
	char	value;

	counter = 0;
	while (str[counter])
	{
		value = str[counter];
		if (!((value > 64 && value < 91) || (value > 96 && value < 123)))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}
