/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:42:36 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/21 10:11:16 by rbasyrov         ###   ########.fr       */
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
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_to_eat;
	int				n_eaten;
	pthread_mutex_t	*lfork_ind;
	pthread_mutex_t	*rfork_ind;
	pthread_mutex_t	*print_permit_mutex;
	long long		start_time;
	struct timeval	last_ate;
	int				full;
	int				forks_were_taken;
	int				left_fork;
	int				right_fork;
	pthread_mutex_t	*n_full_mutex;
	int				*n_full;
	pthread_mutex_t	*dead_mutex;
	int				*dead;
}	t_philosopher;

typedef struct s_context
{
	int				n_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_to_eat;
	t_philosopher	*philos;
	int				failed_philo;
	pthread_mutex_t	*forks;
	int				forks_exist;
	int				failed_fork;
	pthread_t		*tids;
	pthread_mutex_t	print_permit_mutex;
	int				print_permit;
	pthread_mutex_t	n_full_mutex;
	int				n_full;
	pthread_mutex_t	dead_mutex;
	int				dead;
	long long		start_time;
}	t_context;

//main.c
int			main(int argc, char **argv);
int			all_full(t_context *ct);
int			init_context(t_context **ct);
void		join_threads(t_context *ct);
int			supervise(t_context *ct);

//initialise.c
int			init_args(int argc, char **argv, t_context *ct);
int			create_mutexes(t_context *ct);
int			create_forks(t_context *ct);
int			create_philosophers(t_context *ct);

//exit.c
void		destroy_forks(t_context *ct);
void		destroy_philosophers(t_context *ct);
int			exit_with_message(t_context *ct, char *message);
int			clean_exit(t_context *ct);

//utils.c
void		*ft_calloc(size_t count, size_t size);
int			ft_atoi(const char *string);
int			print_action(t_philosopher *phi, char *message);
int			check_death(t_philosopher *phi);

//exist.c
void		*philosopher_exist(void *arg);
int			philosopher_eat(t_philosopher *phi);
void		take_forks(t_philosopher *phi);

//time.c
long long	timeval_to_ms(struct timeval time);
long long	get_time_in_ms(void);
void		usleep_in_intervals(int how_long_to_sleep);
#endif