/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:20:32 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 13:30:57 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	counter;

	counter = 0;
	while (str[counter])
	{
		if (!(str[counter] >= '0' && str[counter] <= '9'))
		{
			return (0);
		}
		counter++;
	}
	return (1);
}
