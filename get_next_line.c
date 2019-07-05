/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:23:11 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/06 00:09:42 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_getbuffer(const int fd, char **line)
{
	char		*buffer;
	char		*temp;
	int			value;

	if ((buffer = (char *)malloc(sizeof(*buffer) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	value = read(fd, buffer, BUFF_SIZE);
	if (value > 0)
	{
		buffer[value] = '\0';
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
	}
	free(buffer);
	return (value);
}

static int		read_and_join(const int fd, char **stack, char **line_feed)
{
	int			bytes;

	while (*line_feed == '\0')
	{
		bytes = ft_getbuffer(fd, *&stack);
		if (bytes == 0)
		{
			if (ft_strlen(*stack) == 0)
				return (0);
			*stack = ft_strjoin(*stack, "\n");
		}
		if (bytes < 0)
			return (-1);
		else
			*line_feed = ft_strchr(*stack, '\n');
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*stack = NULL;
	char		*temp;
	int			ret;
	char		*line_feed;

	if ((!stack && (stack = (char*)malloc(sizeof(*stack))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	line_feed = ft_strchr(stack, '\n');
	ret = read_and_join(fd, &stack, &line_feed);
	if (ret == 0 || ret == -1)
	{
		if (ret == 0)
			*line = ft_strdup("");
		return (ret);
	}
	*line = ft_strsub(stack, 0, ft_strlen(stack) - ft_strlen(line_feed));
	temp = ft_strdup(line_feed + 1);
	ft_strdel(&stack);
	stack = temp;
	return (ret);
}
