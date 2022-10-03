/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:10:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/06 13:10:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

void	ft_sort_int_tab(int *tab, int size)
{
	int	counter1;
	int	counter2;
	int	temp;

	counter1 = 0;
	while (counter1 < size - 1)
	{
		counter2 = counter1;
		while (counter2 < size)
		{
			if (tab[counter1] > tab[counter2])
			{
				temp = tab[counter1];
				tab[counter1] = tab[counter2];
				tab[counter2] = temp;
			}
			counter2++;
		}
		counter1++;
	}
}
