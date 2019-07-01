/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 15:10:38 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/18 09:23:20 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*newstr;

	i = 0;
	j = 0;
	if (s1 && s2)
	{
		newstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
		if (newstr == NULL)
		{
			return (NULL);
		}
		ft_strcpy(newstr, s1);
		ft_strcat(newstr, s2);
		return (newstr);
	}
	return (NULL);
}
