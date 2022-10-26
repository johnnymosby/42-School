/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:13 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/09 16:43:14 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

#ifndef	BUFFER_SIZE
# define BUFFER_SIZE = 42
#endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strdup(char *src);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *string, int c);
int		ft_stringlen(char *str);
#endif

