/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:44:26 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 13:54:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_printable(char *str);

int	ft_str_is_printable(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!((str[counter] > 31) && (str[counter] < 127)))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}
