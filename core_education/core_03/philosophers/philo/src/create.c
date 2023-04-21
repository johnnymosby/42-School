/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:03:50 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 12:04:13 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_mutexes(t_context *ct)
{
	int	fail;

	fail = pthread_mutex_init(&ct->print_permit_mutex, NULL);
	if (fail != 0)
	{
		ct->print_permit = -1;
		return (exit_with_message(ct, "mutex for 'dead' failed"));
	}
	fail = pthread_mutex_init(&ct->dead_mutex, NULL);
	if (fail != 0)
	{
		ct->dead = -1;
		return (exit_with_message(ct, "mutex for 'dead' failed"));
	}
	fail = pthread_mutex_init(&ct->n_full_mutex, NULL);
	if (fail != 0)
	{
		ct->n_full = -100;
		return (exit_with_message(ct, "mutex for 'n_full' failed"));
	}
	return (0);
}

int	create_forks(t_context *ct)
{
	int	i;
	int	fail;

	ct->forks = ft_calloc(ct->n_philos, sizeof(pthread_mutex_t));
	if (ct->forks == NULL)
		exit_with_message(ct, "calloc failed for forks");
	i = 0;
	while (i != ct->n_philos)
	{
		fail = pthread_mutex_init(&ct->forks[i], NULL);
		if (fail != 0)
		{
			ct->failed_fork = i;
			return (exit_with_message(ct, "mutexes for forks failed"));
		}
		ct->forks_exist = 1;
		i++;
	}
	return (0);
}

static int	create_a_philosopher(t_philosopher *phi, int id, t_context *ct)
{
	phi->id = id + 1;
	phi->n_philos = ct->n_philos;
	phi->time_to_die = ct->time_to_die;
	phi->time_to_eat = ct->time_to_eat;
	phi->time_to_sleep = ct->time_to_sleep;
	phi->n_to_eat = ct->n_to_eat;
	phi->lfork_ind = &ct->forks[id];
	if (id == (ct->n_philos - 1))
		phi->rfork_ind = &ct->forks[0];
	else
		phi->rfork_ind = &ct->forks[id + 1];
	phi->dead_mutex = &ct->dead_mutex;
	phi->dead = &ct->dead;
	phi->n_full_mutex = &ct->n_full_mutex;
	phi->n_full = &ct->n_full;
	phi->print_permit_mutex = &ct->print_permit_mutex;
	phi->start_time = ct->start_time;
	return (0);
}

int	create_philosophers(t_context *ct)
{
	int	i;
	int	fail;

	ct->tids = ft_calloc(ct->n_philos, sizeof(pthread_t));
	if (ct->tids == NULL)
		return (exit_with_message(ct, "calloc failed for threads"));
	ct->philos = ft_calloc(ct->n_philos, sizeof(t_philosopher));
	if (ct->philos == NULL)
		return (exit_with_message(ct, "calloc failed for philos"));
	i = 0;
	ct->start_time = get_time_in_ms();
	while (i != ct->n_philos)
	{
		if (create_a_philosopher(&ct->philos[i], i, ct) == 1)
			return (1);
		fail = pthread_create(&ct->tids[i], NULL,
				philosopher_exist, &ct->philos[i]);
		if (fail != 0)
		{
			ct->failed_philo = i;
			return (exit_with_message(ct, "threads failed"));
		}
		i++;
	}
	return (0);
}
