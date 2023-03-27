/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:58:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 17:48:17 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_input(t_context *ct)
{
	if (ct->inp != NULL)
		free(ct->inp);
}

void	free_array(t_context *ct)
{
	if (ct->arr->nums != NULL)
		free(ct->arr->nums);
	ct->arr->nums = NULL;
	if (ct->arr->inds != NULL)
		free(ct->arr->inds);
	ct->arr->inds = NULL;
	free(ct->arr);
	ct->arr = NULL;
}

void	free_stack_a(t_context *ct)
{
	if (ct->st_a->arr != NULL)
		free(ct->st_a->arr);
	free(ct->st_a);
}

void	free_stack_b(t_context *ct)
{
	if (ct->st_b->arr != NULL)
		free(ct->st_b->arr);
	free(ct->st_b);
}

void	free_commands(t_context *ct)
{
	if (ct->cms->ts != NULL)
		free(ct->cms->ts);
	free (ct->cms);
}
