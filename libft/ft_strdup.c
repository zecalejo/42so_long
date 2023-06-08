/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:38:33 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/05/29 22:07:55 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	int		len;

	len = ft_strlen(s);
	s2 = malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	ft_memcpy(s2, s, len + 1);
	return (s2);
}
