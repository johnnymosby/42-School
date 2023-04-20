/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:37:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 13:07:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_protections(t_context *ct)
{
	int	i;
	int	fail;

	ct->protections = ft_calloc(ct->n_philos, sizeof(pthread_mutex_t));
	if (ct->protections == NULL)
		exit_with_message(ct, "calloc failed for protections");
	i = 0;
	while (i != ct->n_philos)
	{
		fail = pthread_mutex_init(&ct->protections[i], NULL);
		if (fail != 0)
		{
			ct->failed_protection = i;
			return (exit_with_message(ct, "mutexes for protections failed"));
		}
		ct->protections_exist = 1;
		i++;
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
	phi->time_to_die = ct->time_to_die;
	phi->time_to_eat = ct->time_to_eat;
	phi->time_to_sleep = ct->time_to_sleep;
	phi->n_to_eat = ct->n_to_eat;
	phi->all_full = &ct->all_full;
	phi->lfork_ind = &ct->forks[id];
	if (id == (ct->n_philos - 1))
		phi->rfork_ind = &ct->forks[0];
	else
		phi->rfork_ind = &ct->forks[id + 1];
	phi->dead = &ct->dead;
	phi->tid = &ct->tids[id];
	phi->print_permit = &ct->print_permit;
	phi->start_time = ct->start_time;
	phi->protection = &ct->protections[id];
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

int	init_args(int argc, char **argv, t_context *ct)
{
	ct->n_philos = ft_atoi(argv[1]);
	if (!(0 < ct->n_philos && ct->n_philos < 201))
		return (exit_with_message(ct, "wrong number of philosophers"));
	ct->time_to_die = ft_atoi(argv[2]);
	if (ct->time_to_die < 0)
		return (exit_with_message(ct, "wrong time to die"));
	ct->time_to_eat = ft_atoi(argv[3]);
	if (ct->time_to_eat < 0)
		return (exit_with_message(ct, "wrong time to eat"));
	ct->time_to_sleep = ft_atoi(argv[4]);
	if (ct->time_to_sleep < 0)
		return (exit_with_message(ct, "wrong time to sleep"));
	if (argc == 6)
	{
		ct->n_to_eat = ft_atoi(argv[5]);
		if (ct->n_to_eat < 1)
			return (exit_with_message(ct, "wrong number of times to eat"));
	}
	else
		ct->n_to_eat = -1;
	ct->failed_fork = -1;
	ct->failed_philo = -1;
	ct->failed_protection = -1;
	return (0);
}
