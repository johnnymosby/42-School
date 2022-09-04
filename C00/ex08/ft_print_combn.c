/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:05:05 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/04 14:05:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		pow_n_base10(int n);
int		n_ones(int n);
int		check(int n);
int		n_nonzeros(int num);
void	ft_print_combn(int n);

int	pow_n_base10(int n)
{
	int	counter;
	int	powered_number;

	counter = 0;
	powered_number = 10;
	while (++counter < n)
	{
		powered_number *= 10;
	}
	return (powered_number);
}

int	n_ones(int n)
{
	int	num_ones;
	int	counter;

	num_ones = 1;
	counter = 1;
	while (++counter <= n)
	{
		num_ones += (counter - 1) * pow_n_base10(counter - 1);
	}
	return (num_ones);
}

int	check(int n)
{
	if ((n % 10) > ((n / 10) % 10))
	{
		check(n / 10);
	}
	else
	{
		return (1);
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
	while (++num <= pow_n_base10(n))
	{
		counter = 0;
		if (check(num) == 0)
		{
			if (num < pow_n_base10(n - 1))
			{
				while (++counter <= (n - n_nonzeros(num)))
				{
					ft_putchar('0');
				}
			}
			ft_putnbr(num);
			if (num != (pow_n_base10(n) - n_ones(n)))
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
	}
}
