/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 22:51:06 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/05/30 02:21:02 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cntdigit(int n)
{
	int	cnt;

	cnt = 0;
	if (n <= 0)
	{
		n *= -1;
		cnt++;
	}
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		size;

	size = ft_cntdigit(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	ptr = (char *)malloc(size + 1);
	if (!ptr)
		return (NULL);
	if (n == 0)
		ptr[0] = '0';
	if (n < 0)
	{
		ptr[0] = '-';
		n *= -1;
	}
	ptr [size] = '\0';
	while (n > 0)
	{
		ptr[size - 1] = ((n % 10) + '0');
		n /= 10;
		size--;
	}
	return (ptr);
}
