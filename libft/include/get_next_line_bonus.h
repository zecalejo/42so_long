/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 16:14:50 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/05/30 13:35:36 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 33
# endif

char	*get_next_line(int fd);
char	*gnl_strjoin(char *s1, char *s2);

size_t	ft_strlen(const char *str);

int		gnl_clnbuf(char *buf);

#endif