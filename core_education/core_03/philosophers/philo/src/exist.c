/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 19:16:32 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_in_order(t_philosopher *phi)
{
	if (phi->id % 2)
	{
		pthread_mutex_lock(phi->rfork_ind);
		if (*phi->dead == 0)
			phi->right_fork = print_action(phi, "has taken a fork");
		pthread_mutex_lock(phi->lfork_ind);
		if (*phi->dead == 0)
			phi->left_fork = print_action(phi, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(phi->lfork_ind);
		if (*phi->dead == 0)
			phi->left_fork = print_action(phi, "has taken a fork");
		pthread_mutex_lock(phi->rfork_ind);
		if (*phi->dead == 0)
			phi->right_fork = print_action(phi, "has taken a fork");
	}
	phi->forks_were_taken = 1;
}

void	take_forks(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
		take_in_order(phi);
	}
	else
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
	}
	phi->forks_were_taken = 1;
}

void	check_death(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	if (phi->n_eaten == 0
		&& phi->time_to_die < (get_time_in_ms() - phi->start_time))
	{
		*phi->dead = 1;
		print_action(phi, "died");
	}
	else if (phi->n_eaten > 0
		&& phi->time_to_die < (get_time_in_ms()
			- timeval_to_ms(phi->last_ate)))
	{
		*phi->dead = 1;
		print_action(phi, "died");
	}
	pthread_mutex_unlock(phi->dead_mutex);
	pthread_mutex_unlock(phi->n_full_mutex);
}

void	start_eating(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
		print_action(phi, "is eating");
		gettimeofday(&phi->last_ate, NULL);
		usleep_in_intervals(phi->time_to_eat);
		phi->n_eaten = phi->n_eaten + 1;
		if (phi->n_eaten == phi->n_to_eat)
		{
			phi->full = 1;
			pthread_mutex_lock(phi->n_full_mutex);
			*phi->n_full = *phi->n_full + 1;
			pthread_mutex_unlock(phi->n_full_mutex);
		}
	}
	else
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
	}
}

void	drop_forks(t_philosopher *phi)
{
	if (phi->forks_were_taken == 1)
	{
		if (phi->id % 2)
		{
			pthread_mutex_unlock(phi->lfork_ind);
			pthread_mutex_unlock(phi->rfork_ind);
		}
		else
		{
			pthread_mutex_unlock(phi->rfork_ind);
			pthread_mutex_unlock(phi->lfork_ind);
		}
	}
	phi->forks_were_taken = 0;
}

int	philosopher_eat(t_philosopher *phi)
{
	take_forks(phi);
	check_death(phi);
	start_eating(phi);
	check_death(phi);
	drop_forks(phi);
	return (0);
}

void	philosopher_sleep(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
		print_action(phi, "is sleeping");
		usleep_in_intervals(phi->time_to_sleep);
	}
	else
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
	}
}

void	philosopher_think(t_philosopher *phi)
{
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	if (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
		print_action(phi, "is thinking");
		usleep(1000);
	}
	else
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
	}
}

void	*philosopher_exist(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	pthread_mutex_lock(phi->n_full_mutex);
	pthread_mutex_lock(phi->dead_mutex);
	while (*phi->n_full < phi->n_philos && *phi->dead == 0)
	{
		pthread_mutex_unlock(phi->dead_mutex);
		pthread_mutex_unlock(phi->n_full_mutex);
		philosopher_eat(phi);
		check_death(phi);
		philosopher_sleep(phi);
		check_death(phi);
		philosopher_think(phi);
		check_death(phi);
		pthread_mutex_lock(phi->n_full_mutex);
		pthread_mutex_lock(phi->dead_mutex);
	}
	pthread_mutex_unlock(phi->dead_mutex);
	pthread_mutex_unlock(phi->n_full_mutex);
	return (NULL);
}
