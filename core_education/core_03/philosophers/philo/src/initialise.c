/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:37:34 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/17 15:26:40 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int argc, char **argv, t_context *ct)
{
	ct->n_philos = ft_atoi(argv[1]);
	if (!(0 < ct->n_philos && ct->n_philos < 201))
		exit_with_message(ct, "wrong number of philosophers");
	ct->time_to_die = ft_atoi(argv[2]);
	if (ct->time_to_die < 0)
		exit_with_message(ct, "wrong time to die");
	ct->time_to_eat = ft_atoi(argv[3]);
	if (ct->time_to_eat < 0)
		exit_with_message(ct, "wrong time to eat");
	ct->time_to_sleep = ft_atoi(argv[4]);
	if (ct->time_to_sleep < 0)
		exit_with_message(ct, "wrong time to sleep");
	if (argc == 6)
	{
		ct->n_to_eat = ft_atoi(argv[5]);
		if (ct->n_to_eat < 1)
			exit_with_message(ct, "wrong number of times to eat");
	}
}

t_context *init_context(void)
{
	t_context	*ct;

	ct = ft_calloc(1, sizeof(t_context));
	if (ct == NULL)
		exit_with_message(NULL, "malloc & ct");
	return (ct);
}
