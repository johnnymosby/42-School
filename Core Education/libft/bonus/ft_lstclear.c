/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbasyrov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 14:52:04 by rbasyrov          #+#    #+#             */
/*   Updated: 2022/10/08 14:52:05 by rbasyrov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	t_list	*l;

	l = *lst;
	if (del && lst)
	{
		while (*lst)
		{
			temp = l->next;
			(*del)(l->content);
			free(l);
			l = temp;
		}
	}
	*lst = l;
}
