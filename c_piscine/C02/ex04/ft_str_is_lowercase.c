/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:38:51 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 13:43:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_lowercase(char *str);

int	ft_str_is_lowercase(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!(str[counter] >= 'a' && str[counter] <= 'z'))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}
