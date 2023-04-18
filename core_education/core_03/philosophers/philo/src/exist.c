/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exist.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:39:33 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/18 19:33:12 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

voi		take_forks

void	philosopher_eat(t_philosopher *phi)
{
	//take_forks(t_philosopher *phi);
	printf("%i\n", phi->id);
}

// void	philosopher_sleep(t_philosopher *phi)
// {
	
// }

// void	philosopher_think(t_philosopher *phi)
// {
	
// }

void	*philosopher_exist(void *arg)
{
	t_philosopher	*phi;

	phi = (t_philosopher *)arg;
	philosopher_eat(phi);
	// while (*phi->dead == 0 && phi->full == 0)
	// {
	// 	philosopher_eat(phi);
	// 	// if (phi->full == 0)
	// 	// 	philosopher_sleep(phi);
	// 	// if (phi->full == 0)
	// 	// 	philosopher_think(phi);
	// 	break ;
	// }
	return (NULL);
}
