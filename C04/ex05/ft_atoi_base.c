/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 13:51:29 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/15 13:51:32 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (*(str + n) != '\0')
	{
		n++;
	}
	return (n);
}

int	ft_distinct_no_sign(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (str[i + j] != '\0')
		{
			if (str[i] == str[i + j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	return (1);
}

int	convert_char(char *str, char to_find, int loc)
{
	int	i;
	int	value;
	int	b;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
		{
			value = ft_strlen(str);
			b = i;
			while (--loc > 0)
				b *= value;
			return (b);
		}
		i++;
	}
	return (-1);
}

int	convert_str(char *str, char *base)
{
	int	i;
	int	j;
	int	nbr;

	nbr = 0;
	i = 0;
	j = 0;
	while (convert_char(base, str[j], j) != -1)
	{
		j++;
	}
	while (i < j && convert_char(base, str[i], j - i) != -1)
	{
		nbr += convert_char(base, str[i], j - i);
		i++;
	}
	return (nbr);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	nbr;

	i = 0;
	n = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
	{
		i++;
	}
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			n *= -1;
		i++;
	}
	if ((ft_strlen(base) > 1) && (ft_distinct_no_sign(base) == 1))
	{
		nbr = convert_str(str + i, base);
		return (nbr * n);
	}
	return (0);
}
