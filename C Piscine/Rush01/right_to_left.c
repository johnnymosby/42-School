/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_to_left.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:27 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:45:29 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	right_to_left(int what_index, char map[4][4])
{
	if (map[what_index][3] == '4')
		return ('1');
	if (map[what_index][2] == '4')
		return ('2');
	if (map[what_index][1] == '4')
	{
		if (map[what_index][3] == '3')
			return ('2');
		else if (map[what_index][2] == '3')
			return ('3');
		else if (map[what_index][2] == '2')
			return ('3');
		else
			return ('2');
	}
	if (map[what_index][3] == '3')
		return ('2');
	else if (map[what_index][2] == '3')
		return ('3');
	else if (map[what_index][3] == '2')
		return ('3');
	else
		return ('4');
}
