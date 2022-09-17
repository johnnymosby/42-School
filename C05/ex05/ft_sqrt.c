/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:22:38 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_posintlen(int nbr)
{
	int	i;

	i = 1;
	while (nbr > 0)
	{
		if (nbr / 10 == 0)
			break ;
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_iterative_power(int nb, int power)
{
	int	value;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	value = nb;
	while (--power > 0)
		nb *= value;
	return (nb);
}

int	ft_sqrt(int nb)
{
	int	i;
	int	j;
	int	len;

	if (nb <= 0)
		return (0);
	len = ft_posintlen(nb);
	i = ft_iterative_power(10, (len - 1) / 2);
	if (len >= 3)
	{
		j = ft_iterative_power(10, len - 2);
		if (nb / j < 5)
			i = i * 2 + i / 5;
	}
	while (i * i < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
