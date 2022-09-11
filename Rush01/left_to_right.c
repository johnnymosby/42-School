/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_to_right.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:17 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:45:19 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	left_to_right(int what_index, char map[4][4])
{
	if (map[what_index][0] == '4')
		return ('1');
	if (map[what_index][1] == '4')
		return ('2');
	if (map[what_index][2] == '4')
	{
		if (map[what_index][0] == '3')
			return ('2');
		else if (map[what_index][1] == '3')
			return ('3');
		else if (map[what_index][1] == '2')
			return ('3');
		else
			return ('2');
	}
	if (map[what_index][0] == '3')
		return ('2');
	else if (map[what_index][1] == '3')
		return ('3');
	else if (map[what_index][0] == '2')
		return ('3');
	else
		return ('4');
}
