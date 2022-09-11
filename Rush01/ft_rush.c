/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rush.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:31:14 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:16 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_matrix(char m[4][4]);
void	update_row_ab(int a, int b, char map[4][4]);
void	update_row_cd(int c, int d, char map[4][4]);
int		check_matrix(char *input, char map[4][4]);
int		check_columns(char map[4][4]);

char	ft_rush(char *inp, char map[4][4])
{
	int	iter[4];

	iter[0] = -1;
	while (++iter[0] < 24)
	{
		iter[1] = -1;
		while (++iter[1] < 24)
		{
			iter[2] = -1;
			while (++iter[2] < 24)
			{
				iter[3] = -1;
				while (++iter[3] < 24)
				{
					update_row_ab(iter[0], iter[1], map);
					update_row_cd(iter[2], iter[3], map);
					if (check_columns(map) == 0 && check_matrix(inp, map) == 0)
						return ('+');
				}
			}
		}
	}
	return ('-');
}
