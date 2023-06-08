/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:13:42 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/05/19 02:19:21 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buf[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	int			i;

	i = 0;
	if (fd < 0 || fd > FOPEN_MAX)
		return (NULL);
	if (BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
	{
		while (buf[fd][i] && fd >= 0 && fd <= FOPEN_MAX)
			buf[fd][i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (buf[fd][0] || read(fd, buf[fd], BUFFER_SIZE) > 0)
	{
		line = gnl_strjoin(line, buf[fd]);
		if (gnl_clnbuf(buf[fd]))
			break ;
	}
	return (line);
}
