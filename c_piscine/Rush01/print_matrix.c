/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:31:36 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:31:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	print_matrix(char m[4][4])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 4)
	{
		while (j < 3)
		{
			ft_putchar(m[i][j]);
			ft_putchar(' ');
			j++;
		}
		ft_putchar(m[i][j]);
		j = 0;
		ft_putchar('\n');
		i++;
	}
}
