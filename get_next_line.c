/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jphasha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 16:23:11 by jphasha           #+#    #+#             */
/*   Updated: 2019/07/09 09:35:38 by jphasha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_get_chunk(const int fd, char **store)
{
	char		*chunk;
	char		*swpr;
	int			characters;

	if ((chunk = (char *)malloc(sizeof(*chunk) * (BUFF_SIZE + 1))) == NULL)
		return (-1);
	characters = read(fd, chunk, BUFF_SIZE);
	if (characters > 0)
	{
		chunk[characters] = '\0';
		swpr = ft_strjoin(*store, chunk);
		free(*store);
		*store = swpr;
	}
	free(chunk);
	return (characters);
}

static int		line_builder(const int fd, char **store, char **line_check)
{
	int			characters;

	while (*line_check == '\0')
	{
		characters = ft_get_chunk(fd, *&store);
		if (characters == 0)
		{
			if (ft_strlen(*store) == 0)
				return (0);
			*store = ft_strjoin(*store, "\n");
		}
		if (characters < 0)
			return (-1);
		else
			*line_check = ft_strchr(*store, '\n');
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	*store = NULL;
	char		*swpr;
	int			ret_val;
	char		*line_grab;

	if ((!store && (store = (char*)malloc(sizeof(*store))) == NULL) || !line
			|| fd < 0 || BUFF_SIZE < 0)
		return (-1);
	line_grab = ft_strchr(store, '\n');
	ret_val = line_builder(fd, &store, &line_grab);
	if (ret_val <= 0)
	{
		if (ret_val == 0)
			*line = ft_strdup("");
		return (ret_val);
	}
	*line = ft_strsub(store, 0, ft_strlen(store) - ft_strlen(line_grab));
	swpr = ft_strdup(line_grab + 1);
	ft_strdel(&store);
	store = swpr;
	return (ret_val);
}
