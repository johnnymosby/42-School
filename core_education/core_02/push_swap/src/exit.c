/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:46:13 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 17:45:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exit_with_message(t_context *ct, char *message)
{
	if (ct->inp != NULL)
		free_input(ct);
	if (ct->arr != NULL)
		free_array(ct);
	if (ct->st_a != NULL)
		free_stack_a(ct);
	if (ct->st_b != NULL)
		free_stack_b(ct);
	if (ct->cms != NULL)
		free_commands(ct);
	ct->inp = NULL;
	ct->arr = NULL;
	ct->st_a = NULL;
	ct->st_b = NULL;
	ct->cms = NULL;
	free(ct);
	ct = NULL;
	ft_printf("Error: %s\n", message);
	exit(EXIT_FAILURE);
}

void	clean_before_end(t_context *ct)
{
	if (ct->inp != NULL)
		free_input(ct);
	if (ct->arr != NULL)
		free_array(ct);
	if (ct->st_a != NULL)
		free_stack_a(ct);
	if (ct->st_b != NULL)
		free_stack_b(ct);
	if (ct->cms != NULL)
		free_commands(ct);
	ct->inp = NULL;
	ct->arr = NULL;
	ct->st_a = NULL;
	ct->st_b = NULL;
	ct->cms = NULL;
	free(ct);
	ct = NULL;
	exit(EXIT_SUCCESS);
}

void	exit_if_not_numbers(char *s, t_context *ct)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (!((s[i] >= '0' && s[i] <= '9')
				|| s[i] == ' '
				|| s[i] == '-'))
		{
			free(s);
			exit_with_message(ct, "wrong characters");
		}
		if (s[i] == '-'
			&& (!(s[i + 1] >= '0' && s[i + 1] <= '9')
				|| !(i == 0 || s[i - 1] == ' ')))
		{
			free(s);
			exit_with_message(ct, "wrongly put '-'");
		}
		i++;
	}
}
