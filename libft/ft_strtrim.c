/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:41:46 by jphasha           #+#    #+#             */
/*   Updated: 2019/06/26 09:53:51 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	trimlen;
	size_t	i;
	size_t	j;

	if (!s)
	{
		return (NULL);
	}
	i = 0;
	j = ft_strlen(s);
	while (s[i] != '\0' && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
	{
		i++;
	}
	while (i < j && (s[j - 1] == '\t' || s[j - 1] == '\n' || s[j - 1] == ' '))
	{
		j--;
	}
	if (i - j == 0)
	{
		return (ft_strnew(1));
	}
	trimlen = j - i;
	return (ft_strsub(s, i, trimlen));
}
