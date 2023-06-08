/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 19:14:59 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/11/07 22:41:56 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s1;

	s1 = malloc(sizeof(t_list));
	if (!s1)
		return (NULL);
	s1->content = content;
	s1->next = NULL;
	return (s1);
}
