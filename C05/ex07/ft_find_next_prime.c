/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:22:55 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:58 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (0);
	while (i * i <= nb && i <= 46340)
	{
		if (nb % i == 0)
			return (i);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	i = 2;
	if (nb < 2)
		return (2);
	while (i <= 2147483647)
	{
		if ((i >= nb) && (ft_is_prime(i) == 1))
			return (i);
		i++;
	}
	return (i);
}
