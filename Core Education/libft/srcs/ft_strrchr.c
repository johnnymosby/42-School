/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:32:12 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:32:13 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *string, int c)
{
	char	*a;
	char	*z;

	a = (char *) string;
	z = (char *) string;
	while (*z)
		z++;
	while (a != z)
	{
		if (c == *z)
			return (z);
		z--;
	}
	return (0);
}
