/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:23:11 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/05 16:18:56 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_content_grab(const int fd, char **line)
{
	char	*content;
	char	*swpr;
	int		value;

	if ((content = (char *)malloc(sizeof(*content) * (BUFF_SIZE + 1))) == NULL)
	{
		return (-1);
	}
	value = read(fd, content, BUFF_SIZE);
	if (value > 0)
	{
		content[value] = '\0';
		swpr = ft_strjoin(*line, content);
		free(*line);
		*line = swpr;
	}
	free(swpr);
	return (value);
}

static int	content_compiler(const int fd, char **storage, char **content_checker);
{
	int		content_size;

	while(content_checker == '\0')
	{
		content_size = ft_content_grab(fd, *&storage);
		if (content_size == 0)
		{
			if (ft_strlen(*storage) == 0)
			{
				return (0);
			}
			*storage = ft_strjoin(*storage, "\n");
		}
		if (content_size < 0)
		{
			return (-1);
		}
		else
		{
			*content_checker = ft_strchr(*storage, '\n');
		}
	}
	return (1);
}
int	get_next_line(const int fd, char **line)
{
}
