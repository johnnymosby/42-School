/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_to_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:40:13 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:40:17 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	up_to_down(int what_index, char map[4][4])
{
	if (map[0][what_index] == '4')
		return ('1');
	if (map[1][what_index] == '4')
		return ('2');
	if (map[2][what_index] == '4')
	{
		if (map[0][what_index] == '3')
			return ('2');
		else if (map[1][what_index] == '3')
			return ('3');
		else if (map[1][what_index] == '2')
			return ('3');
		else
			return ('2');
	}
	if (map[0][what_index] == '3')
		return ('2');
	else if (map[1][what_index] == '3')
		return ('3');
	else if (map[0][what_index] == '2')
		return ('3');
	else
		return ('4');
}
