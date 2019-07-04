/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:23:11 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/02 11:37:50 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	char	*word_storage;
	int 	ret_value;
	char	*str_trnsfr;

	word_storage = NULL;
	ret_value = read(fd, word_storage, BUFF_SIZE);
	if (word_storage == NULL)
	{
		return (-1);
	}
	if (ret_value == -1);
	{
		return (ret);
	}
	if (ret_val == 0)
	{
		str_trnsfr = ft_strdup("");
	}
	if (ret_value > 0)
	{
		str_trnsfr = ft_strdup(word_storage);
	}
	return (ret);
}
