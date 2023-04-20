/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:13:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 13:50:29 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_protections(t_context *ct)
{
	int	i;

	i = 0;
	if (ct->failed_protection >= 0)
	{
		while (i != ct->failed_protection && ct->protections_exist == 1)
		{
			pthread_mutex_destroy(&ct->protections[i]);
			i++;
		}
	}
	else
	{
		while (i != ct->n_philos && ct->protections_exist == 1)
		{
			pthread_mutex_destroy(&ct->protections[i]);
			i++;
		}
	}
}

void	destroy_forks(t_context *ct)
{
	int	i;

	i = 0;
	if (ct->failed_fork >= 0)
	{
		while (i != ct->failed_fork && ct->forks_exist == 1)
		{
			pthread_mutex_destroy(&ct->forks[i]);
			i++;
		}
	}
	else
	{
		while (i != ct->n_philos && ct->forks_exist == 1)
		{
			pthread_mutex_destroy(&ct->forks[i]);
			i++;
		}
	}
}

void	destroy_philosophers(t_context *ct)
{
	int	i;

	i = 0;
	if (ct->failed_philo >= 0)
	{
		while (i != ct->failed_philo && ct->tids[i] != 0)
		{
			printf("FAILED PHILO\n");
			pthread_join(ct->tids[i], NULL);
			i++;
		}
	}
	else
	{
		while (i != ct->n_philos && ct->tids[i] != 0)
		{
			printf("USUAL PHILO\n");
			pthread_join(ct->tids[i], NULL);
			i++;
		}
	}
	ct->tids = NULL;
}

int	exit_with_message(t_context *ct, char *message)
{
	if (ct != NULL && ct->tids != NULL)
	{
		destroy_philosophers(ct);
		free(ct->tids);
		printf("PHILOSOPHERS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->protections != NULL)
	{
		destroy_protections(ct);
		free(ct->protections);
		printf("PROTECTIONS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->forks != NULL)
	{
		destroy_forks(ct);
		free(ct->forks);
		printf("FORKS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->philos != 0)
		free(ct->philos);
	if (ct != NULL)
		free(ct);
	printf("Error: %s\n", message);
	return (1);
}

int	clean_exit(t_context *ct)
{
	if (ct != NULL && ct->tids != NULL)
	{
		destroy_philosophers(ct);
		free(ct->tids);
		printf("PHILOSOPHERS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->protections != NULL)
	{
		destroy_protections(ct);
		free(ct->protections);
		printf("PROTECTIONS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->forks != NULL)
	{
		destroy_forks(ct);
		free(ct->forks);
		printf("FORKS ARE DESTROYED\n");
	}
	if (ct != NULL && ct->philos != 0)
		free(ct->philos);
	if (ct != NULL)
		free(ct);
	printf("CLEAN EXIT\n");
	return (0);
}
