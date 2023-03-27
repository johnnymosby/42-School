/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <rbasyrov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 16:43:13 by rbasyrov          #+#    #+#             */
/*   Updated: 2023/03/27 19:37:24 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);

char	*ft_strdup_upd(char *src);
char	*ft_strjoin_upd(char *s1, char *s2);
char	*ft_strchr_upd(const char *string, int c);
int		ft_stringlen_upd(char *str);
#endif
