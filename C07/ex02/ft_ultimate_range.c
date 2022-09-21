/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:22:47 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/17 20:22:48 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*t;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	t = malloc(sizeof(int) * (max - min));
	if (t == (void *) 0)
	{
		*range = 0;
		return (-1);
	}
	i = 0;
	while (min < max)
	{
		t[i] = min;
		min++;
		i++;
	}
	*range = t;
	return (i);
}
