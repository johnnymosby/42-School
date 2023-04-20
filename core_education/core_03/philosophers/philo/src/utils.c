/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:20 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 10:35:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_bzero(void *block, size_t size)
{
	unsigned char	*b;

	b = block;
	while (size > 0)
	{
		*b = 0;
		b++;
		size--;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;
	size_t	z;

	z = count * size;
	if (count != 0 && z / count != size)
		return (NULL);
	t = malloc(count * size);
	if (!t)
		return (NULL);
	ft_bzero(t, count * size);
	return (t);
}

int	ft_atoi(const char *string)
{
	int						i;
	int						n;
	unsigned long long int	number;

	i = 0;
	n = 1;
	number = 0;
	while (string[i] == ' ' || string[i] == '\f' || string[i] == '\n'
		|| string[i] == '\r' || string[i] == '\t' || string[i] == '\v')
		i++;
	if (string[i] == '+' || string[i] == '-')
	{
		if (string[i] == '-')
			n *= -1;
		i++;
	}
	while ('0' <= string[i] && string[i] <= '9')
	{
		number = number * 10 + (string[i] - '0');
		if (number > 9223372036854775807)
			return ((n != -1) * (-1));
		i++;
	}
	return (n * number);
}

void	print_action(t_philosopher *phi, char *message)
{
	pthread_mutex_lock(phi->print_permit);
	printf("%lld %i %s\n", (get_time_in_ms() - phi->start_time),
		phi->id, message);
	pthread_mutex_unlock(phi->print_permit);
}

void	check_death(t_philosopher *phi)
{
	pthread_mutex_lock(phi->protection);
	if (phi->n_eaten == 0
		&& phi->time_to_die < (get_time_in_ms() - phi->start_time))
	{
		if (*phi->dead == 0)
		{
			*phi->dead = 1;
			print_action(phi, "died");
		}
	}
	else if (phi->n_eaten > 0
		&& phi->time_to_die < (get_time_in_ms()
			- timeval_to_ms(phi->last_ate)))
	{
		if (*phi->dead == 0)
		{
			*phi->dead = 1;
			print_action(phi, "died");
		}
	}
	pthread_mutex_unlock(phi->protection);
}
