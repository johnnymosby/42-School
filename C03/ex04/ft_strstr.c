/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:14:37 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/08 18:14:37 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	unsigned int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

int	ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	loc;
	int	size;
	int zhopa;

	i = 0;
	j = 0;
	loc = 0;
	size = ft_strlen(to_find);
	while (str[i])
	{
		if (str[i] == to_find[j])
		{
			loc = i;
			while (str[i] && to_find[j] && zhopa != 1)
			{
				if (str[i] != to_find[j])
					zhopa = 1;
				i++;
				j++;
			}
			zhopa = 0;
			if (size == j)
				return (loc);
			loc = 0;
			j = 0;
		}
		i++;
	}
	return (-1);
}