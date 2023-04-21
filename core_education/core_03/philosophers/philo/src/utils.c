/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:51:20 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 12:22:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*t;
	size_t			z;
	unsigned char	*b;

	z = count * size;
	if (count != 0 && z / count != size)
		return (NULL);
	t = malloc(count * size);
	if (!t)
		return (NULL);
	b = t;
	while (z > 0)
	{
		*b = 0;
		b++;
		z--;
	}
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

int	print_action(t_philosopher *phi, char *message)
{
	lock_mutexes(phi);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		unlock_mutexes(phi);
		pthread_mutex_lock(phi->print_permit_mutex);
		printf("%lld %i %s\n", (get_time_in_ms() - phi->start_time),
			phi->id, message);
		pthread_mutex_unlock(phi->print_permit_mutex);
	}
	else
		unlock_mutexes(phi);
	return (1);
}

void	lock_mutexes(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
}

void	unlock_mutexes(t_philosopher *phi)
{
	pthread_mutex_unlock(phi->dead_mutex);
	pthread_mutex_unlock(phi->n_full_mutex);
}
