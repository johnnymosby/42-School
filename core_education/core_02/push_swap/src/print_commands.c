/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:13:48 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 13:30:06 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 0	sa
// 1	sb
// 2	pa
// 3	pb
// 4	ra
// 5	rb
// 6	rra
// 7	rrb
// 8	ss
// 9	rr
// 10	rrr

static int	check_if_cms_is_optimisible(t_commands *cms, int i)
{
	if (((cms->ts[i] + cms->ts[i + 1]) == 1)
		|| ((cms->ts[i] == 4 && cms->ts[i + 1] == 5)
			|| (cms->ts[i] == 5 && cms->ts[i + 1] == 4))
		|| ((cms->ts[i] == 6 && cms->ts[i + 1] == 7)
			|| (cms->ts[i] == 7 && cms->ts[i + 1] == 6)))
		return (1);
	else
		return (0);
}

void	print_commands(t_commands *cms)
{
	int	i;

	i = 0;
	while (i != cms->n)
	{
		if (i != (cms->n - 1))
		{
			if ((cms->ts[i] == 0 && cms->ts[i + 1] == 1)
				|| (cms->ts[i] == 1 && cms->ts[i + 1] == 0))
				ft_printf("ss\n");
			else if ((cms->ts[i] == 4 && cms->ts[i + 1] == 5)
				|| (cms->ts[i] == 5 && cms->ts[i + 1] == 4))
				ft_printf("rr\n");
			else if ((cms->ts[i] == 6 && cms->ts[i + 1] == 7)
				|| (cms->ts[i] == 7 && cms->ts[i + 1] == 6))
				ft_printf("rrr\n");
			else
				ft_printf("%s\n", change_number_to_command(cms->ts[i]));
			if (check_if_cms_is_optimisible(cms, i) == 1)
				i++;
		}
		else
			ft_printf("%s\n", change_number_to_command(cms->ts[i]));
		i++;
	}
}

void	print_commands_simple(t_commands *cms)
{
	int	i;

	i = 0;
	while (i != cms->n)
	{
		ft_printf("%s\n", change_number_to_command(cms->ts[i]));
		i++;
	}
}
