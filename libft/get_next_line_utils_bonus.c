/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:18:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/05/30 13:35:36 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (NULL);
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	free(s1);
	while (*s2)
	{
		s3[i++] = *s2;
		if (*s2++ == '\n')
			break ;
	}
	s3[i] = '\0';
	return (s3);
}

int	gnl_clnbuf(char *buf)
{
	int	i;
	int	j;
	int	newln;

	i = 0;
	j = 0;
	newln = 0;
	if (!buf)
		return (0);
	while (buf[i])
	{
		if (newln)
			buf[j++] = buf[i];
		if (buf[i] == '\n')
			newln = 1;
		buf[i++] = '\0';
	}
	return (newln);
}
