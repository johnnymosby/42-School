/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:05:27 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 12:40:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	left_then_right(t_philosopher *phi)
{
	pthread_mutex_lock(phi->lfork_ind);
	lock_mutexes(phi);
	if (*phi->dead == 0)
	{
		unlock_mutexes(phi);
		phi->left_fork = print_action(phi, "has taken a fork");
	}
	else
		unlock_mutexes(phi);
	pthread_mutex_lock(phi->rfork_ind);
	lock_mutexes(phi);
	if (*phi->dead == 0)
	{
		unlock_mutexes(phi);
		phi->right_fork = print_action(phi, "has taken a fork");
	}
	else
		unlock_mutexes(phi);
}

static void	right_then_left(t_philosopher *phi)
{
	pthread_mutex_lock(phi->rfork_ind);
	lock_mutexes(phi);
	if (*phi->dead == 0)
	{
		unlock_mutexes(phi);
		phi->right_fork = print_action(phi, "has taken a fork");
	}
	else
		unlock_mutexes(phi);
	pthread_mutex_lock(phi->lfork_ind);
	lock_mutexes(phi);
	if (*phi->dead == 0)
	{
		unlock_mutexes(phi);
		phi->left_fork = print_action(phi, "has taken a fork");
	}
	else
		unlock_mutexes(phi);
}

static void	take_in_order(t_philosopher *phi)
{
	if (phi->id % 2)
		right_then_left(phi);
	else
		left_then_right(phi);
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
