/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 12:40:16 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philosopher *phi)
{
	lock_mutexes(phi);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		unlock_mutexes(phi);
		print_action(phi, "is eating");
		gettimeofday(&phi->last_ate, NULL);
		usleep_in_intervals(phi->time_to_eat);
		lock_mutexes(phi);
		phi->n_eaten = phi->n_eaten + 1;
		unlock_mutexes(phi);
		if (phi->n_eaten == phi->n_to_eat)
		{
			phi->full = 1;
			pthread_mutex_lock(phi->n_full_mutex);
			*phi->n_full = *phi->n_full + 1;
			pthread_mutex_unlock(phi->n_full_mutex);
		}
	}
	else
		unlock_mutexes(phi);
}

void	philosopher_eat(t_philosopher *phi)
{
	take_forks(phi);
	start_eating(phi);
	drop_forks(phi);
}

void	philosopher_sleep(t_philosopher *phi)
{
	lock_mutexes(phi);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		unlock_mutexes(phi);
		print_action(phi, "is sleeping");
		usleep_in_intervals(phi->time_to_sleep);
	}
	else
		unlock_mutexes(phi);
}

void	philosopher_think(t_philosopher *phi)
{
	lock_mutexes(phi);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		unlock_mutexes(phi);
		print_action(phi, "is thinking");
		usleep(1000);
	}
	else
		unlock_mutexes(phi);
}

void	*philosopher_exist(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	if (phi->n_philos == 1)
	{
		print_action(phi, "has taken a fork");
		usleep_in_intervals(phi->time_to_die);
		return (NULL);
	}
	lock_mutexes(phi);
	while (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		unlock_mutexes(phi);
		philosopher_eat(phi);
		philosopher_sleep(phi);
		philosopher_think(phi);
		lock_mutexes(phi);
	}
	unlock_mutexes(phi);
	return (NULL);
}
