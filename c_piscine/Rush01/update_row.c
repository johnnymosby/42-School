/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_row.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:31:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	update_row_ab(int a, int b, char map[4][4])
{
	int		i;
	char	*array1;
	char	*array2;

	array1 = "123412431324134214321423213421432314234124312413";
	array2 = "321432413124314234123421423142134321431241324123";
	i = -1;
	while (++i < 4)
	{
		if (a < 12)
			map[0][i] = *(array1 + 4 * a + i);
		else
			map[0][i] = *(array2 + 4 * (a - 12) + i);
	}
	i = -1;
	while (++i < 4)
	{
		if (b < 12)
			map[1][i] = *(array1 + 4 * b + i);
		else
			map[1][i] = *(array2 + 4 * (b - 12) + i);
	}
}

void	update_row_cd(int c, int d, char map[4][4])
{
	int		i;
	char	*array1;
	char	*array2;

	array1 = "123412431324134214321423213421432314234124312413";
	array2 = "321432413124314234123421423142134321431241324123";
	i = -1;
	while (++i < 4)
	{
		if (c < 12)
			map[2][i] = *(array1 + 4 * c + i);
		else
			map[2][i] = *(array2 + 4 * (c - 12) + i);
	}
	i = -1;
	while (++i < 4)
	{
		if (d < 12)
			map[3][i] = *(array1 + 4 * d + i);
		else
			map[3][i] = *(array2 + 4 * (d - 12) + i);
	}
}
