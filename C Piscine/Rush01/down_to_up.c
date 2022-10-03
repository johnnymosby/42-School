/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_to_up.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:53 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:45:56 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	down_to_up(int what_index, char map[4][4])
{
	if (map[3][what_index] == '4')
		return ('1');
	if (map[2][what_index] == '4')
		return ('2');
	if (map[1][what_index] == '4')
	{
		if (map[3][what_index] == '3')
			return ('2');
		else if (map[2][what_index] == '3')
			return ('3');
		else if (map[2][what_index] == '2')
			return ('3');
		else
			return ('2');
	}
	if (map[3][what_index] == '3')
		return ('2');
	else if (map[2][what_index] == '3')
		return ('3');
	else if (map[3][what_index] == '2')
		return ('3');
	else
		return ('4');
}
