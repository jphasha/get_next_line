/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 15:49:32 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/21 09:40:40 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (substr[i] == '\0')
	{
		return ((char *)(str));
	}
	while (str[i] != '\0')
	{
		j = 0;
		if (str[i] == substr[j])
		{
			while (str[i + j] == substr[j] && (i + ft_strlen(substr) <= len))
			{
				if (substr[j + 1] == '\0')
				{
					return ((char *)(str + i));
				}
				j++;
			}
		}
		i++;
	}
	return (NULL);
}
