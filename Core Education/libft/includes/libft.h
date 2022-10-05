/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:47:49 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/04 18:47:52 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include "stdlib.h"

int		ft_atoi(const char *string);
void	ft_bzero(void *block, size_t size);

int	ft_isalnum(int c);
int	ft_isalpha(int c);
int	ft_isascii(int c);
int	ft_isdigit(int c);
int	ft_isprint(int c);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *a1, const void *a2, size_t size);
void	*ft_memcpy(void *to, const void *from, size_t size);
void	*ft_memmove(void *to, const void *from, size_t size);
void	*ft_memset(void *block, int c, size_t size);





char	*ft_strchr(const char *string, int c);



size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int	ft_strncmp(const char *s1, const char *s2, size_t size);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *string, int c);


int	ft_tolower(int c);
int	ft_toupper(int c);

#endif
