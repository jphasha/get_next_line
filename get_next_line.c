/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:23:11 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/05 20:45:18 by jphasha          ###   ########.fr       */
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
	free(content);
	return (value);
}

static int	content_compiler(const int fd, char **storage, char **content_checker)
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
	static char	*storage = NULL;
	char		*swpr;
	int			cc_value;
	char		*content_checker;

	if ((!storage && (storage = (char *)malloc(sizeof(*storage))) == NULL) || 
			!line || fd < 0 || BUFF_SIZE < 0)
	{
		return (-1);
	}
	content_checker = ft_strchr(storage, '\n');
	cc_value = content_compiler(fd, &storage, &content_checker);
	if (cc_value == 0 || cc_value == -1)
	{
		if (cc_value == 0)
		{
			*line = ft_strdup("");
		}
		return (cc_value);
	}
	*line = ft_strsub(storage, 0, ft_strlen(storage) - ft_strlen(content_checker));
	swpr = ft_strdup(content_checker + 1);
	ft_strdel(&storage);
	storage = swpr;
	return (cc_value);
}
