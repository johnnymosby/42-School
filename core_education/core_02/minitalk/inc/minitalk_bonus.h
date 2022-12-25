/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 17:24:03 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/12/24 22:45:08 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include "../lib/libft/libft.h"

typedef struct byte
{
	unsigned char	bit_0 : 1;
	unsigned char	bit_1 : 1;
	unsigned char	bit_2 : 1;
	unsigned char	bit_3 : 1;
	unsigned char	bit_4 : 1;
	unsigned char	bit_5 : 1;
	unsigned char	bit_6 : 1;
	unsigned char	bit_7 : 1;
}					t_byte;

#endif