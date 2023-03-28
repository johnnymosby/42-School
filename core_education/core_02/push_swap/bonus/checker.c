/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:45:35 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/28 11:06:27 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	if_command(char *command)
{
	if (ft_strcmp(command, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(command, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(command, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(command, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(command, "rrr\n") == 0)
		return (1);
	else
		return (0);
}

static void	move(char *command, t_context *ct)
{
	if (ft_strcmp(command, "sa\n") == 0)
		ft_sa(ct->st_a);
	else if (ft_strcmp(command, "sb\n") == 0)
		ft_sb(ct->st_b);
	else if (ft_strcmp(command, "ss\n") == 0)
		ft_ss(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "pa\n") == 0)
		ft_pa(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "pb\n") == 0)
		ft_pb(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "ra\n") == 0)
		ft_ra(ct->st_a);
	else if (ft_strcmp(command, "rb\n") == 0)
		ft_rb(ct->st_b);
	else if (ft_strcmp(command, "rr\n") == 0)
		ft_rr(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "rra\n") == 0)
		ft_rra(ct->st_a);
	else if (ft_strcmp(command, "rrb\n") == 0)
		ft_rrb(ct->st_b);
	else
		ft_rrr(ct->st_a, ct->st_b);
}

static int	check_if_sorted(t_context *ct)
{
	int	n;

	n = ct->st_a->n - 1;
	while (n != 0)
	{
		if (ct->st_a->arr[n] != (ct->st_a->arr[n - 1] - 1))
		{
			return (0);
		}
		n--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_context	*ct;
	char		*cmd;

	ct = init_context();
	ct->inp = parse_input(argc, argv, ct);
	init_array(ct->inp, ct);
	init_stack_a(ct->arr, ct);
	create_stack_b(ct->arr, ct);
	while (1)
	{
		cmd = get_next_line(STDIN_FILENO);
		if (cmd == NULL)
			break ;
		if (if_command(cmd) == 0)
			exit_with_message(ct, "not a command");
		move(cmd, ct);
	}
	if (check_if_sorted(ct) == 1 && ct->st_b->n == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_before_end(ct);
}
//ARG="2 3 6 1"; ./push_swap $ARG | ./checker $ARG