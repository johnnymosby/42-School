/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:31:58 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:59 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	check_array(int what_side, int what_index,	char map[4][4]);

int	check_matrix(char *inp, char map[4][4])
{
	int	a;
	int	b;
	int	x;
	int	y;

	x = 1;
	y = 0;
	a = -1;
	while (++a < 4)
	{
		b = -1;
		while (++b < 4)
		{
			if (a == 0 && (check_array(a, b, map) != *(inp + 2 * b)))
				return (x);
			else if (a == 1 && (check_array(a, b, map) != *(inp + 8 + 2 * b)))
				return (x);
			else if (a == 2 && (check_array(a, b, map) != *(inp + 16 + 2 * b)))
				return (x);
			else if (a == 3 && (check_array(a, b, map) != *(inp + 24 + 2 * b)))
				return (x);
		}
	}
	return (y);
}
