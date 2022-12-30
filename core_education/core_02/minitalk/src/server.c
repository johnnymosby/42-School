/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:23:20 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/24 22:47:44 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	receive_bit(int bit, int *i)
{
	static t_byte	g_byte_to_receive;

	if (*i == 1)
		g_byte_to_receive.bit_0 = bit;
	else if (*i == 2)
		g_byte_to_receive.bit_1 = bit;
	else if (*i == 3)
		g_byte_to_receive.bit_2 = bit;
	else if (*i == 4)
		g_byte_to_receive.bit_3 = bit;
	else if (*i == 5)
		g_byte_to_receive.bit_4 = bit;
	else if (*i == 6)
		g_byte_to_receive.bit_5 = bit;
	else if (*i == 7)
		g_byte_to_receive.bit_6 = bit;
	else if (*i == 8)
	{
		g_byte_to_receive.bit_7 = bit;
		ft_putchar_fd(*(unsigned char *)&g_byte_to_receive, 1);
		*i = 0;
	}
}

void	receive_character(int signum)
{
	static int	i;

	if (i == 0)
		i = 1;
	if (signum == SIGUSR1)
		receive_bit(0, &i);
	else if (signum == SIGUSR2)
		receive_bit(1, &i);
	if (signum == SIGUSR1 || signum == SIGUSR2)
		i++;
}

int	main(void)
{
	struct sigaction	sa;	
	int					pid;

	sa.sa_handler = &receive_character;
	sa.sa_flags = SA_RESTART;
	pid = getpid();
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	while (1)
		pause();
	return (0);
}
