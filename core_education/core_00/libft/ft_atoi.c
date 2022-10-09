/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 12:07:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/14 12:07:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *string)
{
	int						i;
	int						n;
	unsigned long long int	number;

	i = 0;
	n = 1;
	number = 0;
	while (string[i] == ' ' || string[i] == '\f' || string[i] == '\n'
		|| string[i] == '\r' || string[i] == '\t' || string[i] == '\v')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			n *= -1;
		i++;
	}
	while ('0' <= string[i] && string[i] <= '9')
	{
		number = number * 10 + (string[i] - '0');
		if (number > 9223372036854775807)
			return ((n != -1) * (-1));
		i++;
	}
	return (n * number);
}
