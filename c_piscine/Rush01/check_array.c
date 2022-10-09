/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:30:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:30:21 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	up_to_down(int what_index, char map[4][4]);
char	down_to_up(int what_index, char map[4][4]);
char	left_to_right(int what_index, char map[4][4]);
char	right_to_left(int what_index, char map[4][4]);

char	check_array(int what_side, int what_index,	char map[4][4])
{
	if (what_side == 0)
	{
		return (up_to_down(what_index, map));
	}
	else if (what_side == 1)
	{
		return (down_to_up(what_index, map));
	}
	else if (what_side == 2)
	{
		return (left_to_right(what_index, map));
	}
	else
	{
		return (right_to_left(what_index, map));
	}
}
