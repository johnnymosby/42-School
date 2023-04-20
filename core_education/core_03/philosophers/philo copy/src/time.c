/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:42:08 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/19 12:32:34 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	timeval_to_ms(struct timeval time)
{
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

long long	get_time_in_ms(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return (timeval_to_ms(now));
}

void	usleep_in_intervals(int how_long_to_sleep)
{
	struct timeval	start;
	long long		finish;
	long long		now;

	gettimeofday(&start, NULL);
	now = timeval_to_ms(start);
	finish = now + how_long_to_sleep;
	while (now < finish)
	{
		usleep(100);
		now = get_time_in_ms();
	}
}
