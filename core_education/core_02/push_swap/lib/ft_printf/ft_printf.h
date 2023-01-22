/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:33:45 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/11 15:33:47 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_putchar(char c);
int		ft_putstr(char *str);
char	*ft_strcreate(char *src);

int		ft_printf(const char *fmt, ...);

int		ft_printf_i(va_list ap);
int		ft_printf_p(va_list ap);
int		ft_printf_s(va_list ap);
int		ft_printf_u(va_list ap);
int		ft_printf_x(va_list ap);
int		ft_printf_xbig(va_list ap);

#endif
