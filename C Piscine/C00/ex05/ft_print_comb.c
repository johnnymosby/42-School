/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:26:32 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/05 14:54:42 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_comb(void);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_comb(void)
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
