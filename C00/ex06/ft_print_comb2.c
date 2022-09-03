/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:10:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/03 18:10:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb2(void);

void	ft_print_comb2(void)
{
	char	number1;
	char	number2;
	char	number3;

	number1 = '0' - 1;
	while (++number1 <= '8')
	{
		number2 = number1;
		while (++number2 <= '8')
		{
			number3 = number2;
			while (++number3 <= '9')
			{
				ft_putchar(number1);
				ft_putchar(number2);
				ft_putchar(number3);
				if (number1 != '7' || number2 != '8' || number3 != '9')
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
