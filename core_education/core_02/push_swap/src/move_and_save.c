/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_and_save.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:03:27 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/23 11:44:22 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_and_save(char *command, t_context *ct)
{
	add_command(ct->cms, command, ct);
	if (ft_strcmp(command, "sa") == 0)
		ft_sa(ct->st_a);
	else if (ft_strcmp(command, "sb") == 0)
		ft_sb(ct->st_b);
	else if (ft_strcmp(command, "ss") == 0)
		ft_ss(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "pa") == 0)
		ft_pa(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "pb") == 0)
		ft_pb(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "ra") == 0)
		ft_ra(ct->st_a);
	else if (ft_strcmp(command, "rb") == 0)
		ft_rb(ct->st_b);
	else if (ft_strcmp(command, "rr") == 0)
		ft_rr(ct->st_a, ct->st_b);
	else if (ft_strcmp(command, "rra") == 0)
		ft_rra(ct->st_a);
	else if (ft_strcmp(command, "rrb") == 0)
		ft_rrb(ct->st_b);
	else
		ft_rrr(ct->st_a, ct->st_b);
}
