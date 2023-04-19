/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:44:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/19 17:00:34 by rbasyrov         ###   ########.fr       */
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
		if (ct->philos[i].full == 0)
			return (0);
	}
	return (1);
}

void	supervise(t_context *ct)
{
	int	i;

	while (ct->dead == 0)
	{
		i = 0;
		while (i < ct->n_philos)
		{
			if (ct->dead == 1)
				pthread_detach(ct->tids[i]);
			i++;
		}
	}
}

// int	supervise(t_context *ct)
// {
// 	int	i;

// 	while (all_full(ct) == 0)
// 	{
// 		i = 0;
// 		while (i < ct->n_philos && all_full(ct) == 0)
// 		{
// 			if (ct->dead == 1)
// 				return (clean_exit(ct));
// 			i++;
// 		}
// 	}
// 	return (1);
// }

void	join_threads(t_context *ct)
{
	int	i;

	i = 0;
	while (i < ct->n_philos && ct->tids[i] != 0)
	{
		pthread_join(ct->tids[i], NULL);
		i++;
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
	return (clean_exit(ct));
}
