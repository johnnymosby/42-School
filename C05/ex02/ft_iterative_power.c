/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:22:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/15 17:22:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
