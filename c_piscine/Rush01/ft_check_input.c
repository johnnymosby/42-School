/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 19:31:11 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 19:31:15 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	ft_check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[2 * i] > 52 || str[2 * i] < 49) && i < 16)
			return ('-');
		i++;
	}
	return ('+');
}
