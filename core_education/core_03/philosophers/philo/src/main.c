/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:44:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/18 19:27:31 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (create_forks(ct) == 1)
		return (1);
	if (create_philosophers(ct) == 1)
		return (1);
	//wait until someone dies
	//free everything
	return (clean_exit(ct));
}
