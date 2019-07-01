/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 17:09:23 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/19 13:49:43 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*caster;
	char	oc;
	size_t	i;

	caster = (char *)s;
	oc = (char)c;
	i = ft_strlen(caster);
	while (i > 0 && caster[i] != oc)
	{
		i--;
	}
	if (caster[i] == oc)
	{
		return (caster + i);
	}
	return (NULL);
}
