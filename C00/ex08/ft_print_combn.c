/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:05:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/05 15:14:53 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		pow_10_n_ones(int process_as_pow_10, int n);
void	ft_putcharnbr(int process_char, char c, int nb);
int		check(int num, int n);
int		n_nonzeros(int num);
void	ft_print_combn(int n);

void	ft_putcharnbr(int process_char, char c, int nb)
{
	if (process_char == 1)
	{
		write(1, &c, 1);
	}
	else
	{
		if (nb < 0)
		{
			ft_putcharnbr(1, '-', 0);
			nb *= -1;
		}
		if (nb >= 10)
		{
			ft_putcharnbr(0, ' ', nb / 10);
			ft_putcharnbr(0, ' ', nb % 10);
		}
		else
		{
			ft_putcharnbr(1, nb + '0', 0);
		}
	}
}

int	pow_10_n_ones(int process_as_pow_10, int n)
{
	int	counter;
	int	powered_number;
	int	num_ones;

	if (process_as_pow_10 == 1)
	{
		counter = 0;
		powered_number = 1;
		while (++counter <= n)
		{
			powered_number *= 10;
		}
		return (powered_number);
	}
	else
	{
		num_ones = 1;
		counter = 1;
		while (++counter <= n)
		{
			num_ones += (counter - 1) * pow_10_n_ones(1, counter - 1);
		}
		return (num_ones);
	}
}

int	check(int num, int n)
{
	int	n_symbols;
	int	changed_num;
	int	counter;
	int	pow_10;

	n_symbols = 0;
	changed_num = num;
	while (changed_num > 0)
	{
		n_symbols++;
		changed_num /= 10;
	}
	counter = 1;
	while (n_symbols > 0)
	{
		pow_10 = pow_10_n_ones(1, counter - 1);
		if ((num / pow_10) % 10 <= ((num / pow_10_n_ones(1, counter)) % 10))
		{
			return (1);
		}
		n_symbols--;
		counter++;
	}
	return (0);
}

int	n_nonzeros(int num)
{
	int	n;

	n = 1;
	while (num / 10 > 0)
	{
		n++;
		num /= 10;
	}
	return (n);
}

void	ft_print_combn(int n)
{
	int	num;
	int	counter;

	num = 0;
	while (++num <= pow_10_n_ones(1, n))
	{
		counter = 0;
		if (check(num, n) == 0)
		{
			if (num < pow_10_n_ones(1, n - 1))
			{
				while (++counter <= (n - n_nonzeros(num)))
				{
					ft_putcharnbr(1, '0', 0);
				}
			}
			ft_putcharnbr(0, ' ', num);
			if (num != (pow_10_n_ones(1, n) - pow_10_n_ones(0, n)))
			{
				ft_putcharnbr(1, ',', 0);
				ft_putcharnbr(1, ' ', 0);
			}
		}
	}
}
