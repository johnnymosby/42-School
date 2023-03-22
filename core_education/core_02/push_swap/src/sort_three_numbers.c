/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:18:15 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/22 16:39:26 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_numbers(t_stack_a *st_a, t_commands *cms, t_context *ct)

void	sort_less_than_four_numbers(t_stack_a *st_a, t_commands *cms,
		t_context *ct)
{
	if (st_a->n == 2 && st_a->arr[0] < st_a->arr[1])
		add_command("sa", cms, ct);
	else if (st_a->n == 3)
		sort_three_numbers(st_a, cms, ct);
}
