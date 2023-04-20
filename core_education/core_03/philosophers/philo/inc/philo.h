/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:42:36 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/20 12:16:59 by rbasyrov         ###   ########.fr       */
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
	int				*all_full;
	pthread_mutex_t	*lfork_ind;
	pthread_mutex_t	*rfork_ind;
	pthread_t		*tid;
	pthread_mutex_t	*print_permit;
	long long		start_time;
	struct timeval	last_ate;
	pthread_mutex_t	*protection;
	int				protection_exists;
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
	int				all_full;
	t_philosopher	*philos;
	pthread_mutex_t	*forks;
	int				forks_exist;
	int				failed_fork;
	pthread_t		*tids;
	int				failed_philo;
	pthread_mutex_t	print_permit;
	long long		start_time;
	pthread_mutex_t	*protections;
	int				failed_protection;
	int				protections_exist;
	int				dead;
}	t_context;

//main.c
int			main(int argc, char **argv);
int			all_full(t_context *ct);
int			init_context(t_context **ct);
void		join_threads(t_context *ct);
void		supervise(t_context *ct);

//initialise.c
int			init_args(int argc, char **argv, t_context *ct);
int			create_protections(t_context *ct);
int			create_forks(t_context *ct);
int			create_philosophers(t_context *ct);

//exit.c
void		destroy_forks(t_context *ct);
int			exit_with_message(t_context *ct, char *message);
int			clean_exit(t_context *ct);

//utils.c
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *string);
void		print_action(t_philosopher *phi, char *message);
void		check_death(t_philosopher *phi);

//exist.c
void		*philosopher_exist(void *arg);
void		philosopher_eat(t_philosopher *phi);
void		take_forks(t_philosopher *phi);

//time.c
long long	timeval_to_ms(struct timeval time);
long long	get_time_in_ms(void);
void		usleep_in_intervals(int how_long_to_sleep);
#endif