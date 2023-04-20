/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 13:39:06 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *phi)
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

void	philosopher_eat(t_philosopher *phi)
{
	if (*phi->dead == 0 && *phi->all_full == 0)
		take_forks(phi);
	if (*phi->dead == 0 && *phi->all_full == 0)
	{
		print_action(phi, "is eating");
		gettimeofday(&phi->last_ate, NULL);
		usleep_in_intervals(phi->time_to_eat);
		phi->n_eaten = phi->n_eaten + 1;
	}
	if (phi->id % 2 && phi->forks_were_taken == 1)
	{
		if (phi->left_fork == 1)
		{
			pthread_mutex_unlock(phi->lfork_ind);
			phi->left_fork = 0;
		}
		if (phi->right_fork == 1)
		{
			pthread_mutex_unlock(phi->rfork_ind);
			phi->right_fork = 0;
		}
		phi->forks_were_taken = 0;
	}
	else if (phi->forks_were_taken == 1)
	{
		if (phi->right_fork == 1)
		{
			pthread_mutex_unlock(phi->rfork_ind);
			phi->right_fork = 0;
		}
		if (phi->left_fork == 1)
		{
			pthread_mutex_unlock(phi->lfork_ind);
			phi->left_fork = 0;
		}
		phi->forks_were_taken = 0;
	}
}

void	philosopher_sleep(t_philosopher *phi)
{
	if (*phi->dead == 0 && *phi->all_full == 0)
	{
		print_action(phi, "is sleeping");
		usleep_in_intervals(phi->time_to_sleep);
	}
}

void	philosopher_think(t_philosopher *phi)
{
	if (*phi->dead == 0 && *phi->all_full == 0)
	{
		print_action(phi, "is thinking");
		usleep(100);
	}
}

void	*philosopher_exist(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	while (*phi->dead == 0 && *phi->all_full == 0)
	{
		philosopher_eat(phi);
		if (*phi->all_full == 0)
			philosopher_sleep(phi);
		if (*phi->all_full == 0)
			philosopher_think(phi);
	}
	return (NULL);
}
