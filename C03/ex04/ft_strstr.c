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

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;
	int	loc;
	int	zhopa;

	i = -1;
	while (str[++i])
	{
		j = 0;
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
			if (ft_strlen(to_find) == j)
				return (str + loc);
		}
	}
	return (0);
}
