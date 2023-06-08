/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 00:13:57 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/10 00:37:32 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*l;

	if (!lst)
		return (NULL);
	nlst = ft_lstnew(f(lst->content));
	l = nlst;
	lst = lst->next;
	while (lst)
	{
		l->next = ft_lstnew(f(lst->content));
		if (!l)
			ft_lstclear(&l, del);
		lst = lst->next;
		l = l->next;
	}
	return (nlst);
}
