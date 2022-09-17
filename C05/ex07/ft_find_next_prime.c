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

	if (nb == 2 || nb == 3)
		return (1);
	if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	i = 5;
	while (i * i <= nb && i <= 46340)
	{
		if (nb % i == 0 || nb % (i + 2) == 0)
			return (0);
		i += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (nb == 3)
		return (3);
	if (nb <= 5)
		return (5);
	if (ft_is_prime(nb) == 1)
		return (nb);
	if (nb / 6 * 6 + 1 >= nb)
	{
		if (ft_is_prime(nb / 6 * 6 + 1) == 1)
			return (nb / 6 * 6 + 1);
	}
	nb = nb / 6 * 6 + 5;
	while (nb <= 2147483647)
	{
		if (ft_is_prime(nb) == 1)
			return (nb);
		if (ft_is_prime(nb + 2) == 1)
			return (nb + 2);
		nb += 6;
	}
	return (nb);
}
