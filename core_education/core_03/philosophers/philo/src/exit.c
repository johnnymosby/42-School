/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:13:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/04/17 14:46:39 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	exit_with_message(t_context *ct, char *message)
{
	if (ct != NULL)
		free(ct);
	printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}
