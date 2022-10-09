/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_columns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:30:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:30:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_to_int(char num);

int	pow_2_n_ones(int n)
{
	int	counter;
	int	powered_number;

	counter = 0;
	powered_number = 1;
	while (++counter <= n)
	{
		powered_number *= 2;
	}
	return (powered_number);
}

int	check_columns(char map[4][4])
{
	int	c;
	int	i;
	int	j;
	int	x;
	int	y;

	j = -1;
	x = 1;
	y = 0;
	while (++j < 4)
	{
		i = -1;
		c = 0;
		while (++i < 4)
		{
			c += pow_2_n_ones(char_to_int(map[i][j]));
		}
		if (c != 15)
			return (x);
	}
	return (y);
}
