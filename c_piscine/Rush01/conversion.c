/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:30:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/11 17:30:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	char_to_int(char num)
{
	if (num == '4')
		return (3);
	if (num == '3')
		return (2);
	if (num == '2')
		return (1);
	if (num == '1')
		return (0);
	return (-1);
}

char	int_to_char(int num)
{
	if (num == 3)
		return ('4');
	if (num == 2)
		return ('3');
	if (num == 1)
		return ('2');
	if (num == 0)
		return ('1');
	return ('-');
}
