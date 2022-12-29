/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:23:20 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/29 19:47:56 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void receive_message(int pid, siginfo_t *info, void *context)
{
	static int					i = 0;
	static pid_t				client_pid = 0;
	static unsigned char		byte_to_receive = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	byte_to_receive |= (pid == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (byte_to_receive == 0)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar_fd(byte_to_receive, 1);
		kill(client_pid, SIGUSR1);
		byte_to_receive = 0;
	}
	else
		byte_to_receive <<= 1;
}

int main(void)
{
	struct sigaction	sa;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_sigaction = receive_message;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
