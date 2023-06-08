/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 15:20:53 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/10/28 23:26:14 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	i = 0;
	str = NULL;
	if (!s1 || !set)
		return (NULL);
	if (s1 && set)
	{
		len = ft_strlen(s1);
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[len - 1] && ft_strchr(set, s1[len - 1]) && len > i)
			len--;
		str = (char *)malloc(len - i + 1);
		if (!str)
			return (NULL);
		ft_strlcpy(str, &s1[i], len - i + 1);
	}
	return (str);
}
