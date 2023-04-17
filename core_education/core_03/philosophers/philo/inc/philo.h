/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:42:36 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/17 15:30:53 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philosopher
{
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_to_eat;
	int				n_eaten;
	pthread_mutex_t	*lfork_ind;
	pthread_mutex_t	*rfork_ind;
	pthread_t		tid;
	pthread_mutex_t	*print_permit;
	long long		start_time;
	struct timeval	last_ate;
	int				*dead;
	int				full;
}	t_philosopher;

typedef struct s_context
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_to_eat;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	pthread_t		*tids;
	pthread_mutex_t	print_permit;
	long long		start_time;
	int				dead;
}	t_context;

//main.c
int			main(int argc, char **argv);

//initialise.c
t_context	*init_context(void);
void		init_args(int argc, char **argv, t_context *ct);

//exit.c
void		exit_with_message(t_context *ct, char *message);

//utils.c
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *string);
#endif