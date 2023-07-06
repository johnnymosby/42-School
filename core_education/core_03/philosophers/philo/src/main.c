/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:44:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/22 07:26:32 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philosopher *phi)
{
	int	ret;

	ret = 0;
	lock_mutexes(phi);
	if ((*phi->dead == 0) && ((phi->n_eaten == 0
				&& phi->time_to_die < (get_time_in_ms() - phi->start_time))
			|| (phi->n_eaten > 0
				&& phi->time_to_die < (get_time_in_ms()
					- timeval_to_ms(phi->last_ate)))))
	{
		*phi->dead = 1;
		if (*phi->n_full < phi->n_philos)
		{
			pthread_mutex_lock(phi->print_permit_mutex);
			printf("%lld %i died\n", (get_time_in_ms() - phi->start_time),
				phi->id);
			pthread_mutex_unlock(phi->print_permit_mutex);
		}
		unlock_mutexes(phi);
		ret = 1;
	}
	else
		unlock_mutexes(phi);
	return (ret);
}

int	supervise(t_context *ct)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < ct->n_philos)
		{
			if (check_death(&ct->philos[i]) == 1)
				return (1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_context	*ct;

	if (argc != 5 && argc != 6)
		return (exit_with_message(NULL, "wrong number of arguments"));
	if (init_context(&ct) == 1)
		return (1);
	if (init_args(argc, argv, ct) == 1)
		return (1);
	if (create_mutexes(ct) == 1)
		return (1);
	if (create_forks(ct) == 1)
		return (1);
	if (create_philosophers(ct) == 1)
		return (1);
	supervise(ct);
	return (clean_exit(ct));
}
