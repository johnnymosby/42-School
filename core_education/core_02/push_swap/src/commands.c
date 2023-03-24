/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:13:57 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/24 13:44:56 by rbasyrov         ###   ########.fr       */
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
int	change_command_to_number(char *command)
{
	if (ft_strcmp(command, "sa") == 0)
		return (0);
	if (ft_strcmp(command, "sb") == 0)
		return (1);
	if (ft_strcmp(command, "pa") == 0)
		return (2);
	if (ft_strcmp(command, "pb") == 0)
		return (3);
	if (ft_strcmp(command, "ra") == 0)
		return (4);
	if (ft_strcmp(command, "rb") == 0)
		return (5);
	if (ft_strcmp(command, "rra") == 0)
		return (6);
	if (ft_strcmp(command, "rrb") == 0)
		return (7);
	if (ft_strcmp(command, "ss") == 0)
		return (8);
	if (ft_strcmp(command, "rr") == 0)
		return (9);
	return (10);
}

char	*change_number_to_command(int num)
{
	if (num == 0)
		return ("sa");
	if (num == 1)
		return ("sb");
	if (num == 2)
		return ("pa");
	if (num == 3)
		return ("pb");
	if (num == 4)
		return ("ra");
	if (num == 5)
		return ("rb");
	if (num == 6)
		return ("rra");
	if (num == 7)
		return ("rrb");
	if (num == 8)
		return ("ss");
	if (num == 9)
		return ("rr");
	return ("rrr");
}

t_commands	*create_commands(t_context *ct)
{
	t_commands *cms;

	cms = ft_calloc(1, sizeof(t_commands));
	if (cms == NULL)
		exit_with_message(ct, "malloc & commands");
	cms->ts = malloc(sizeof(int) * SIZE_COMMANDS_LIST);
	if (cms->ts == NULL)
		exit_with_message(ct, "malloc & commands");
	cms->n = 0;
	cms->max = SIZE_COMMANDS_LIST;
	return (cms);
}

// ret for array to return
void	increase_cms(t_commands *cms, t_context *ct)
{
	int	*ret;
	int	size;
	int	i;

	size = (int)(1.5 * cms->max);
	ret = ft_calloc(size, sizeof(int));
	if (ret == NULL)
		exit_with_message(ct, "malloc & increase of commands_list");
	i = 0;
	while (i != cms->max)
	{
		ret[i] = cms->ts[i];
		i++;
	}
	free(cms->ts);
	cms->ts = ret;
	cms->max = size;
}

void	add_command(t_commands *cms, char *command, t_context *ct)
{
	if (cms->n == cms->max)
		increase_cms(cms, ct);
	cms->ts[cms->n] = change_command_to_number(command);
	cms->n += 1;
}
