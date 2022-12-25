/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:23:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/25 11:38:51 by rbasyrov         ###   ########.fr       */
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

void	send_string(char *s, int pid)
{
	t_byte	byte_to_send;
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		*(unsigned char *)&byte_to_send = (unsigned char)s[i];
		send_bit(byte_to_send.bit_0, pid);
		send_bit(byte_to_send.bit_1, pid);
		send_bit(byte_to_send.bit_2, pid);
		send_bit(byte_to_send.bit_3, pid);
		send_bit(byte_to_send.bit_4, pid);
		send_bit(byte_to_send.bit_5, pid);
		send_bit(byte_to_send.bit_6, pid);
		send_bit(byte_to_send.bit_7, pid);
		i++;
	}
}

void	receive_signal_back(int sig, siginfo_t *info, void *context)
{
	static int	n_received;

	(void)info;
	(void)context;
	if (sig == SIGUSR1)
		++n_received;
	else if (sig == SIGUSR2)
	{
		ft_putnbr_fd(n_received, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		ft_putstr_fd("Proper usage: ./client [PID] [message].\n", 1);
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Wrong PID", 1);
		return (0);
	}
	ft_putstr_fd("n sent: ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putstr_fd("\nn received: ", 1);
	sa.sa_sigaction = &receive_signal_back;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	send_string(argv[2], pid);
	while (1)
		pause();
	return (0);
}
