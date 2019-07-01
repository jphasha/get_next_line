/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 14:32:20 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/19 15:01:12 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (needle[i] == '\0')
	{
		return ((char *)(haystack));
	}
	while (haystack[i] != '\0')
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (needle[j] == haystack[i + j])
			{
				if (needle[j + 1] == '\0')
				{
					return ((char *)(haystack + i));
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
