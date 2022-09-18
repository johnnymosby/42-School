/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_str.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 15:36:54 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/09/18 15:36:56 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRS_TO_TAB
# define FT_STRS_TO_TAB

typedef struct s_stock_str	t_stock_str;
struct s_stock_str
{
	int		size;
	char	*str;
	char	*copy;
};

#endif
