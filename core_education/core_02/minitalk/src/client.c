/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:23:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/24 22:25:46 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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

void	send_character(char c, int pid)
{
	t_byte	byte_to_send;

	*(unsigned char *)&byte_to_send = (unsigned char)c;
	send_bit(byte_to_send.bit_0, pid);
	send_bit(byte_to_send.bit_1, pid);
	send_bit(byte_to_send.bit_2, pid);
	send_bit(byte_to_send.bit_3, pid);
	send_bit(byte_to_send.bit_4, pid);
	send_bit(byte_to_send.bit_5, pid);
	send_bit(byte_to_send.bit_6, pid);
	send_bit(byte_to_send.bit_7, pid);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid <= 0)
		{
			ft_putstr_fd("Wrong PID", 1);
			return (0);
		}
		i = 0;
		while (argv[2][i])
		{
			send_character(argv[2][i], pid);
			i++;
		}
	}
	else
	{
		ft_putstr_fd("Proper usage: ./client [PID] [message].\n", 1);
	}
	return (0);
}
