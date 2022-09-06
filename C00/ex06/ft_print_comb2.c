/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 18:10:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/05 15:00:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);
int		check(int num, int n);
void	ft_putnbr(int nb);
void	ft_print_comb2(void);
void	print_numbers(int num1, int num2);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + '0');
	}
}

void	print_numbers(int num1, int num2)
{
	if (num1 < 10)
	{
		write(1, "0", 1);
	}
	ft_putnbr(num1);
	write(1, " ", 1);
	if (num2 < 10)
	{
		write(1, "0", 1);
	}
	ft_putnbr(num2);
	if (num1 != 98)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = -1;
	while (++num1 < 99)
	{
		num2 = 0;
		while (++num2 < 100)
		{
			if (num1 < num2)
			{
				print_numbers(num1, num2);
			}
		}
	}
}
