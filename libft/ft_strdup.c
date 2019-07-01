/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 10:17:24 by event             #+#    #+#             */
/*   Updated: 2019/06/18 16:25:31 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*srccpy;

	i = 0;
	srccpy = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (srccpy == NULL)
	{
		return (NULL);
	}
	ft_strcpy(srccpy, src);
	return (srccpy);
}
