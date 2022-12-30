/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:23:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/29 19:59:38 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	listen_to_server(int sig)
{
	static int	n_characters = 0;

	if (sig == SIGUSR2)
	{
		ft_putnbr_fd(n_characters, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
	n_characters++;
}

void	send_bit(int bit, int pid)
{
	int	check_if_error;

	if (bit == 0)
	{
		check_if_error = kill(pid, SIGUSR1);
		if (check_if_error == -1)
		{
			ft_putstr_fd("Error sending signal.\n", 1);
			exit(1);
		}
	}
	else
	{
		check_if_error = kill(pid, SIGUSR2);
		if (check_if_error == -1)
		{
			ft_putstr_fd("Error sending signal.\n", 1);
			exit(1);
		}
	}
	usleep(100);
}

void	send_message(int pid, char *message)
{
	int		i;
	char	c;

	while (*message != '\0')
	{
		i = 8;
		c = *message;
		message++;
		while (i--)
		{
			if (c >> i & 1)
				send_bit(1, pid);
			else
				send_bit(0, pid);
			usleep(100);
		}
	}
	i = 8;
	while (i--)
	{
		send_bit(0, pid);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || ft_strlen(argv[1]) == 0)
	{
		ft_putstr_fd("Wrong input\n", 1);
		return (1);
	}
	ft_putstr_fd("n of sent:      ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putstr_fd("\nn of received:  ", 1);
	signal(SIGUSR1, listen_to_server);
	signal(SIGUSR2, listen_to_server);
	send_message(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}
