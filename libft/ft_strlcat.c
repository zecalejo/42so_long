/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:32:56 by jnuncio-          #+#    #+#             */
/*   Updated: 2022/10/18 15:38:17 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstlen;
	size_t	srclen;	

	if (size == 0 && (!src || !dst))
		return (0);
	dstlen = ft_strlen((const char *)dst);
	srclen = ft_strlen(src);
	i = dstlen;
	j = 0;
	if (size <= dstlen)
		return (size + srclen);
	while (src[j] && j < (size - dstlen - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dstlen + srclen);
}
