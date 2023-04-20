/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:44:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 14:54:32 by rbasyrov         ###   ########.fr       */
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

int	all_full(t_context *ct)
{
	int	i;

	i = 0;
	while (i < ct->n_philos)
	{
		pthread_mutex_lock(&ct->protections[i]);
		if (ct->philos[i].full == 0)
		{
			pthread_mutex_unlock(&ct->protections[i]);
			return (0);
		}
		pthread_mutex_lock(&ct->protections[i]);
		i++;
	}
	return (1);
}
void	check_hunger(t_philosopher *phi)
{
	pthread_mutex_lock(phi->protection);
	if (phi->n_eaten == phi->n_to_eat)
		phi->full = 1;
	pthread_mutex_unlock(phi->protection);
}

void	supervise(t_context *ct)
{
	int	i;

	ct->all_full = all_full(ct);
	while (ct->dead == 0 && ct->all_full == 0)
	{
		i = 0;
		while (i < ct->n_philos)
		{
			check_death(&ct->philos[i]);
			if (ct->dead == 1)
				break ;
			check_hunger(&ct->philos[i]);
			i++;
		}
		ct->all_full = all_full(ct);
	}
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
	if (create_protections(ct) == 1)
		return (1);
	if (create_forks(ct) == 1)
		return (1);
	if (create_philosophers(ct) == 1)
		return (1);
	supervise(ct);
	printf("SUPERVISE FINISHED\n");
	return (clean_exit(ct));
}
