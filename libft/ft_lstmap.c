/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/31 00:16:19 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:13:07 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_first;
	t_list	*new_next;

	if (!lst)
		return (0);
	new_first = ft_lstnew((*f)(lst->content));
	if (!new_first)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		new_next = ft_lstnew((*f)(lst->content));
		if (!new_next)
		{
			ft_lstclear(&new_first, del);
			return (0);
		}
		ft_lstadd_back(&new_first, new_next);
	}
	return (new_first);
}
