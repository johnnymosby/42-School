/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:10:13 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/06 13:10:13 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size);

void	ft_rev_int_tab(int *tab, int size)
{
	int	temp;
	int	counter;

	counter = -1;
	while (++counter < size / 2)
	{
		temp = *(tab + counter);
		*(tab + counter) = *(tab + size - 1 - counter);
		*(tab + size - 1 - counter) = temp;
	}
}
