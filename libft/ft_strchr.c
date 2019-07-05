/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 16:34:52 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/04 14:56:02 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*caster;
	char	oc;
	size_t	i;

	caster = (char *)s;
	oc = (char)c;
	i = 0;
	while (s[i] != oc)
	{
		if (caster[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (caster + i);
}
