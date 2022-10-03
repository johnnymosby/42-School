/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraymund <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:01:12 by rraymund          #+#    #+#             */
/*   Updated: 2022/09/04 17:42:33 by rraymund         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);
void	ft_putchar(char c);
void	outside_line(int x, int y, int a);
void	inside_line(int x, int y, int a);

void	inside_line(int x, int y, int a)
{
	int	b;

	b = 0;
	while (++b <= x)
	{
		if (a == 1 || a == y || b == 1 || b == x)
		{
			ft_putchar('*');
		}
		else
		{
			ft_putchar(' ');
		}
	}
}

void	outside_line(int x, int y, int a)
{
	int	b;

	b = 0;
	while (++b <= x)
	{
		if ((a == 1 && b == 1) || (a == y && b == x))
		{
			ft_putchar('/');
		}
		else if ((a == 1 && b == x) || (a == y && b == 1))
		{
			ft_putchar('\\');
		}
		else
		{
			ft_putchar('*');
		}
	}
}

void	rush(int x, int y)
{
	int	a;

	a = 0;
	if (x <= 0 || y <= 0)
	{
	}
	else
	{
		while (++a <= y)
		{
			if (a == 1 || a == y)
			{
				outside_line(x, y, a);
			}
			else
			{
				inside_line(x, y, a);
			}
			ft_putchar('\n');
		}
	}
}
