/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 09:21:35 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/14 15:47:41 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	cb;
	size_t			i;

	str = (unsigned char *)s;
	cb = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == cb)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}
