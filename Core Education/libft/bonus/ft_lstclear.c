
#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;
	if (del && lst)
	{
		while(*lst)
		{
			temp = *lst->next;
			(*del)(*lst->content);
			free(*lst);
			*lst = temp;
		}
	}
}
