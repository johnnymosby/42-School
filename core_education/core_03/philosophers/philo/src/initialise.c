/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:37:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 12:04:33 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_context(t_context **ct)
{
	*ct = ft_calloc(1, sizeof(t_context));
	if (*ct == NULL)
		return (exit_with_message(NULL, "malloc & ct"));
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
	return (0);
}
