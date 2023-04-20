/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/19 22:35:25 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philosopher *phi)
{
	if (phi->id % 2)
	{
		pthread_mutex_lock(phi->rfork_ind);
		if (*phi->dead == 0)
			print_action(phi, "has taken a fork");
		pthread_mutex_lock(phi->lfork_ind);
		if (*phi->dead == 0)
			print_action(phi, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(phi->lfork_ind);
		if (*phi->dead == 0)
			print_action(phi, "has taken a fork");
		pthread_mutex_lock(phi->rfork_ind);
		if (*phi->dead == 0)
			print_action(phi, "has taken a fork");
	}
}

void	philosopher_eat(t_philosopher *phi)
{
	pthread_mutex_lock(phi->protection);
	take_forks(phi);
	if (*phi->dead == 0)
		print_action(phi, "is eating");
	phi->n_eaten = phi->n_eaten + 1;
	if (phi->n_eaten == phi->n_to_eat)
		phi->full = 1;
	gettimeofday(&phi->last_ate, NULL);
	usleep_in_intervals(phi->time_to_eat);
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
	pthread_mutex_unlock(phi->protection);
}

void	philosopher_sleep(t_philosopher *phi)
{
	if (*phi->dead == 0)
		print_action(phi, "is sleeping");
	usleep_in_intervals(phi->time_to_sleep);
}

void	philosopher_think(t_philosopher *phi)
{
	print_action(phi, "is thinking");
	usleep(10);
}

void	*philosopher_exist(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	/*philosopher_eat(phi);

	if (phi->full == 0)
		philosopher_sleep(phi);*/

	while (*phi->dead == 0 && phi->full == 0)
	{
		philosopher_eat(phi);
		check_death(phi);
		if (phi->full == 0)
		{
			philosopher_sleep(phi);
			check_death(phi);
			philosopher_think(phi);
			check_death(phi);
		}
		/*if (phi->full == 0)
		{
			philosopher_sleep(phi);
			check_death(phi);
		}*/
		/*if (phi->full == 0)
		{x
			philosopher_think(phi);
			check_death(phi);
		}*/
		//printf("is thinking\n");
	}
	return (NULL);
}
