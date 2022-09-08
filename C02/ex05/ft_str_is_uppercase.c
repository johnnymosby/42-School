/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:44:55 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 13:45:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_uppercase(char *str);

int	ft_str_is_uppercase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!(str[counter] > 64 && str[counter] < 91))
		{
			return (1);
		}
		counter++;
	}
	if (counter == 0)
	{
		return (1);
	}
	return (0);
}
