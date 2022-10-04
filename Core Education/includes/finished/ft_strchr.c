/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:24:10 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 13:24:11 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *string, int c)
{
	char	*p;

	p = (char *) string;
	while (*p)
	{
		if (c == *p)
			return (p);
		p++;
	}
	return (0);
}
