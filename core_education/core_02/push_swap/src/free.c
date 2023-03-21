/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 11:58:02 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/21 15:27:45 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_context(t_context *ct)
{
	free(ct);
}

void	free_input(t_context *ct)
{
	if (ct->inp != NULL)
		free(ct->inp);
}

void	free_array(t_context *ct)
{
	if (ct->arr->nums != NULL)
		free(ct->arr->nums);
	if (ct->arr->inds != NULL)
		free(ct->arr->inds);
	free(ct->arr);
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
}
